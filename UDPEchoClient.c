/*********************************************************
*
* Module Name: Password Breaker
*
* Author: Jared Klingenberger <klinge2@clemson.edu>
*
* File Name:    UDPEchoClient.c
*
* Summary:
*  This file codes the password breaker client.
*
* Revisions:
*
* Methods:
*
*  void clientCNTCCode():
*    Handles SIGINT signals.
*
*  void generatePassword(char pass[], int N):
*    o  pass: Character array to place the new password
*    o  N: Length of password to generate
*    Increments the password with LSB on the left.
*
*  char getNextChar(char c):
*    o  c: current character
*    Returns the character in the sequence following c.
*
*  void end(int exitCode):
*    o  exitCode: Code to pass to exit()
*    Quits the program and outputs time elapsed.
*
*********************************************************/

#include "UDPEcho.h"
#include <signal.h>

#define VERBOSE 0

void clientCNTCCode();
void generatePassword(char pass[], int N);
char getNextChar(char c);
void end(int exitCode);

struct timeval tv_start;
int attempts = 0;

int main(int argc, char *argv[])
{
    int sock;                        /* Socket descriptor */
    struct sockaddr_in echoServAddr; /* Echo server address */
    struct sockaddr_in fromAddr;     /* Source address of echo */
    struct hostent *thehost;         /* Hostent from gethostbyname() */
    unsigned short echoServPort;     /* Echo server port */
    unsigned int fromSize;           /* In-out of address size for recvfrom() */
    char *servIP;                    /* IP address of server */
    char echoBuffer[ECHOMAX+1];      /* Buffer for receiving echoed string */
    int respStringLen;               /* Length of received response */
    char *respCode;                  /* Response code from the server */
    int N;                           /* Length of password to guess */
    int index;                       /* Index of bit to increment */
    struct timeval tv_to;            /* Timeout struct */
    char *pass;                      /* Password char array */
    int retry;

    gettimeofday(&tv_start, NULL);

    /* Test for correct number of arguments */
    if (argc != 4) {
        fprintf(stderr,"Usage: %s <Server IP> <Port> <N>]\n", argv[0]);
        end(1);
    }

    signal (SIGINT, clientCNTCCode);

    servIP = argv[1];              /* First arg: server IP address (dotted quad) */
    echoServPort = atoi(argv[2]);  /* Second arg: server port */
    N = atoi(argv[3]);             /* Third arg: password length */

    /* Check sanity of N */
    if (N < 1) {
        fprintf(stderr, "N value not sane: %d\n", N);
        end(1);
    }

    /* Reserve memory for the password */
    pass = (char*) malloc(sizeof(char)*N + 1);
    memset(pass, '0', N+1);
    pass[0] = '0'-1;
    pass[N] = '\0';

    /* Create a datagram/UDP socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Set socket timeout */
    tv_to.tv_sec = 1;    // seconds
    tv_to.tv_usec = 0;   // microseconds
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv_to, sizeof(struct timeval));

    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));    /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                 /* Internet addr family */
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);  /* Server IP address */
    echoServAddr.sin_port   = htons(echoServPort);     /* Server port */

    /* If user gave a dotted decimal address, we need to resolve it  */
    if (echoServAddr.sin_addr.s_addr == -1) {
        thehost = gethostbyname(servIP);
            echoServAddr.sin_addr.s_addr = *((unsigned long *) thehost->h_addr_list[0]);
    }

    respCode = "FAILURE";
    retry = 0;
    while (strcmp(respCode, "SUCCESS") != 0) {
        if (retry == 0)
            generatePassword(pass, N);
        /* Send the string to the server */
        if (VERBOSE)
            printf("UDPEchoClient: Send the string: %s to the server: %s \n", pass, servIP);    
        if (sendto(sock, pass, strlen(pass), 0, (struct sockaddr *)
                   &echoServAddr, sizeof(echoServAddr)) != strlen(pass))
          DieWithError("sendto() sent a different number of bytes than expected");
  
        /* Recv a response */
        fromSize = sizeof(fromAddr);
        respStringLen = recvfrom(sock, echoBuffer, ECHOMAX, 1, 
             (struct sockaddr *) &fromAddr, &fromSize);

        /* Check for errors */
        if (respStringLen < 0 && (errno == EWOULDBLOCK || errno == EAGAIN)) {
             /* Dropped packet */
             retry = 1;
             continue;
        }

        attempts++;

        if (echoServAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr) {
            fprintf(stderr,"Error: received a packet from unknown source \n");
        }
        /* null-terminate the received data */
        echoBuffer[respStringLen] = '\0';
        if (VERBOSE)
            printf("UDPEchoClient:  Received the following (%d bytes) data: %s\n",respStringLen,echoBuffer);

        respCode = echoBuffer;

        /* Interpret server response */
        if (strcmp(respCode, "SUCCESS") == 0) {
            printf("Successfully cracked the password: %s\n", pass);
        } else if (strcmp(respCode, "FAILURE") == 0) {
            //if (VERBOSE)
                //printf("Incorrect password: %s\n", pass);
        } else
            fprintf(stderr,"Unknown response code %s\n",respCode);
    }

    close(sock);
    end(0);
}

void generatePassword(char pass[], int N) {
    int i, overflow = 1;
    for (i = 0; i < N && overflow == 1; i++) {
        char c = getNextChar(pass[i]);
        pass[i] = c;
        overflow = (c == '0') ? 1 : 0;
    }
}

char getNextChar(char c) {
    switch (c) {
        case '9':
            c = 'A';
            break;
        case 'Z':
            c = 'a';
            break;
        case 'z':
            c = '0';
            break;
        default:
            c++;
    }
    return c;
}

void clientCNTCCode() {
    printf("UDPEchoClient:  CNT-C Interrupt,  exiting....\n");
    end(0);
}

void end(int exitCode) {
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    long usecs = ((tv_end.tv_sec - tv_start.tv_sec)*1000000L
                   + tv_end.tv_usec) - tv_start.tv_usec;
    float secs = (float) usecs / 1000000.;
    printf("Attempts: %d\tTime: %f seconds\n", attempts, secs);
    exit(exitCode);
}

