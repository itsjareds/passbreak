#include "UDPEcho.h"


void DieWithError(char *errorMessage);  /* External error handling function */
void generatePassword(char* pass, const int len);  /* Password generation function */

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
    char *currentPassword = NULL;    /* Current generated password */

    if (argc < 3)         /* Test for correct number of parameters */
    {
        fprintf(stderr,"Usage:  %s <UDP SERVER PORT> <N> <INITIAL PASSWORD>\n",
            argv[0]);
        exit(1);
    }

    /* Seed rand() with the unix timestamp */
    srand(time(NULL));

    echoServPort = atoi(argv[1]);  /* First arg:  local port */
    N = atoi(argv[2]);             /* Second arg: password length */
    generatePassword(currentPassword, N);
    
    /* Set the initial password if provided */
    if (argc >= 4)
        currentPassword = argv[3];

    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Construct local address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));   /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                /* Internet address family */
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    echoServAddr.sin_port = htons(echoServPort);      /* Local port */

    /* Bind to the local address */
    printf("UDPEchoServer: About to bind to port %d\n", echoServPort);    
    if (bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("bind() failed");
    printf("UDPEchoServer: Now listening on port %d\n", echoServPort);
  
    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        cliAddrLen = sizeof(echoClntAddr);

        /* Block until receive message from a client */
        if ((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0,
            (struct sockaddr *) &echoClntAddr, &cliAddrLen)) < 0)
            DieWithError("recvfrom() failed");

        printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

        /* Send received datagram back to the client */
        if (sendto(sock, echoBuffer, recvMsgSize, 0, 
             (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr)) != recvMsgSize)
            DieWithError("sendto() sent a different number of bytes than expected");
    }
    /* NOT REACHED */
}

void generatePassword(char* pass, const int N) {
    char vals[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    if (pass != NULL)
        free(pass);
    pass = (char*) malloc(sizeof(char) * N + 1);
    int i;
    for (i = 0; i < N; i++)
        pass[i] = vals[rand()*62];
    pass[i] = '\0';

    printf("Generated password: %s\n", pass);
}
