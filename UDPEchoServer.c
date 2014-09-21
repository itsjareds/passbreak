/***************************************************************
*
* Module Name: Password Server
*
* Author: Jared Klingenberger <klinge2@clemson.edu>
*
* File Name: UDPEchoServer.c
*
* Summary:
*  Generates a random character password with N chars.
*
* Revisions:
*
* Methods:
*
*  void cntcHandler():
*    Handle SIGINT signals and exits.
*
*  void generatePassword(char pass[], const int len):
*    o  pass: Character array to place the password
*    o  len: Length of password to generate
*    Generates a random character sequence of len chars,
*     then places the sequence into pass[].
*
*  void sendMessage(int sock, const char* message,
*        size_t recvMsgSize, const struct sockaddr *clientAddr,
*        socklen_t addrLen):
*    o  sock: Socket file descriptor
*    o  message: String message to send
*    o  recvMsgSize: Length of message to send
*    o  clientAddr: Client address struct to send to.
*    o  addrLen: Size of clientAddr.
*    Helper function to send messages more simply.
*
*  void updateClient(Client client):
     o  client: struct client to update the client list
*    Add to or update the client list with client information.
*
*  int findClient(char *addr):
*    o  IP address string to search the client list
*    Find a client in the client list based on IP address.
*
*  void printClients():
*    Output the list of clients to stdout.
*
***************************************************************/ 

#include "UDPEcho.h"
#include <signal.h>

#define VERBOSE 0

typedef struct {
    char *addr;
    int attempts;
    int success;
} Client;

void DieWithError(char *errorMessage);  /* External error handling function */
void cntcHandler(); /* ^C handler */
void generatePassword(char pass[], const int len);  /* Password generation function */
void sendMessage(int sock, const char* message, size_t recvMsgSize,
                  const struct sockaddr *clientAddr, socklen_t addrLen);
void updateClient(Client client);
int findClient(char *addr);
void printClients();

Client iplist[255];
int iplen;

int main(int argc, char *argv[])
{
    int sock;                        /* Socket */
    struct sockaddr_in echoServAddr; /* Local address */
    struct sockaddr_in echoClntAddr; /* Client address */
    unsigned int cliAddrLen;         /* Length of incoming message */
    char echoBuffer[ECHOMAX];        /* Buffer for echo string */
    unsigned short echoServPort;     /* Server port */
    int recvMsgSize;                 /* Size of received message */
    int N;                           /* Length of passwords */
    char *pass;                      /* Current generated password */

    if (argc < 3)         /* Test for correct number of parameters */
    {
        fprintf(stderr,"Usage:  %s <UDP SERVER PORT> <N> <INITIAL PASSWORD>\n",
            argv[0]);
        exit(1);
    }

    /* Seed rand() with the unix timestamp */
    srand(time(NULL));

    signal(SIGINT, cntcHandler);

    echoServPort = atoi(argv[1]);  /* First arg:  local port */
    N = atoi(argv[2]);             /* Second arg: password length */

    /* Ensure a sane N */
    if (N < 1) {
        fprintf(stderr,"N value not sane\n");
        exit(1);
    }

    pass = (char*) malloc(sizeof(char)*N + 1);
    generatePassword(pass, N);
    
    /* Set the initial password if provided */
    if (argc >= 4) {
        /* Count number of characters in arg[3] */
        int i = 0;
        while (argv[3][i] != '\0')
            i++;

        /* Suggested password length did not match N */
        if (N != i) {
            fprintf(stderr,"UDPEchoServer: Note: N did not match input password length\n");
            N = i;

            /* Resize pass */
            free(pass);
            pass = (char*) malloc(sizeof(char)*N + 1);
	}
        /* Copy argv[3] into pass */
        i = 0;
        while (i < N && (pass[i] = argv[3][i]) != '\0')
            i++;
        pass[i] = '\0';
    }

    if (VERBOSE)
        printf("UDPEchoServer: Using password %s\n", pass);

    /* Initialize array of client structs to zero */
    memset(&iplist, 0, sizeof(Client)*255);
    iplen = 0;

    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Construct local address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));   /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                /* Internet address family */
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    echoServAddr.sin_port = htons(echoServPort);      /* Local port */

    /* Bind to the local address */
    if (bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("bind() failed");
    if (VERBOSE)
        printf("UDPEchoServer: Now listening on port %d\n", echoServPort);
  
    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        cliAddrLen = sizeof(echoClntAddr);

        /* Block until receive message from a client */
        if ((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0,
            (struct sockaddr *) &echoClntAddr, &cliAddrLen)) < 0)
            DieWithError("recvfrom() failed");

        /* Build client struct for client list */
        Client c;
        memset(&c, 0, sizeof(Client));
        c.addr = (char*) malloc(sizeof(char)*17);
        strcpy(c.addr, inet_ntoa(echoClntAddr.sin_addr));

        if (VERBOSE)
            printf("Handling client %s\n", c.addr);

        /* Convert to a null-terminated string (don't care about bits past N-1) */
        echoBuffer[N] = '\0';

        /* Compare input to password */
        if (strcmp(echoBuffer, pass) == 0) {
            /* Send SUCCESS to the client */
            if (VERBOSE)
                printf("PASSWORD CRACKED! guess: %s  actual: %s\n", echoBuffer, pass);
            sendMessage(sock, "SUCCESS", 8, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));
            generatePassword(pass, N);
            if (VERBOSE)
                printf("Using password %s\n", pass);
            c.success = 1;
        } else {
            /* Send FAILURE to the client */
            if (VERBOSE)
                printf("Incorrect! guess: %s  actual: %s\n", echoBuffer, pass);
            sendMessage(sock, "FAILURE", 8, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));
        }
        c.attempts = 1;

        /* Update client list */
        updateClient(c);

        fflush(stdout);
    }
    /* NOT REACHED */
}

void cntcHandler() {
    printf("Received SIGINT, quitting...\n");

    /* Generate statistics */
    int numAttempts = 0;
    int numSuccess = 0;
    int i;
    for (i = 0; i < iplen; i++) {
        if (iplist[i].addr != 0) {
            numAttempts += iplist[i].attempts;
            numSuccess += iplist[i].success;
        }
    }

    printf("%d\t%d\n", numAttempts, numSuccess);
    printClients();
    exit(0);
}

/* Precondition: pass[] is instantiated with N+1 bytes of memory */
void generatePassword(char pass[], const int N) {
    static char vals[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    /* Generate random character sequence */
    int i;
    for (i = 0; i < N; i++)
        pass[i] = vals[rand()%62];
    pass[N] = '\0';
}

void sendMessage(int sock, const char* message, size_t recvMsgSize,
                  const struct sockaddr *clientAddr, socklen_t addrLen) {
    int len = sendto(sock, message, recvMsgSize, 0, clientAddr, addrLen);
    if (len != recvMsgSize)
        DieWithError("sendto() sent a different number of bytes than expected");
}

void updateClient(Client client) {
    /* Check if the client is already in the table */
    int index = findClient(client.addr);
    if (index < 0)
       index = iplen++;
    if (iplist[index].addr != 0)
        free(iplist[index].addr);

    /* Update entry */
    iplist[index].addr = client.addr;
    iplist[index].attempts += client.attempts;
    iplist[index].success += client.success;
}

/* Search for a client in iplist based on IP string */
int findClient(char *addr) {
    int i;
    for (i = 0; i < iplen; i++) {
        if (iplist[i].addr != 0) {
            if (strcmp(addr, iplist[i].addr) == 0)
                break;
        }
    }
    return (i < iplen) ? i : -1;
}

void printClients() {
    int i;
    for (i = 0; i < iplen; i++) {
        if (iplist[i].addr != 0) {
            printf("%s\n", iplist[i].addr);
        }
    }
}

