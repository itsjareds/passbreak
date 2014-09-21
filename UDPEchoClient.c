/*********************************************************
*
* Module Name: UDP Echo client source 

* File Name:    UDPEchoClient.c
*
* Summary:
*  This file contains the echo client code.
*
* Revisions:
*
*********************************************************/
#include "UDPEcho.h"
#include <signal.h>


void clientCNTCCode();
void generatePassword(char pass[], int N, int *index);
void increment(char pass[], int N, int *index);
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
    char *echoString;                /* String to send to echo server */
    char echoBuffer[ECHOMAX+1];      /* Buffer for receiving echoed string */
    int respStringLen;               /* Length of received response */
    char *respCode;                  /* Response code from the server */
    int N;                           /* Length of password to guess */
    int index;                       /* Index of bit to increment */
    struct timeval tv_to;            /* Timeout struct */
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
    echoString = (char*) malloc(sizeof(char)*N + 1);
    /* Signify that echoString is uninitialized */
    index = -1;

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
            generatePassword(echoString, N, &index);
        /* Send the string to the server */
        printf("UDPEchoClient: Send the string: %s to the server: %s \n", echoString,servIP);    
        if (sendto(sock, echoString, strlen(echoString), 0, (struct sockaddr *)
                   &echoServAddr, sizeof(echoServAddr)) != strlen(echoString))
          DieWithError("sendto() sent a different number of bytes than expected");
  
        /* Recv a response */
        fromSize = sizeof(fromAddr);
        respStringLen = recvfrom(sock, echoBuffer, ECHOMAX, 1, 
             (struct sockaddr *) &fromAddr, &fromSize);

        /* Check for errors */
        if (respStringLen < 0) {
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
        printf("UDPEchoClient:  Received the following (%d bytes) data: %s\n",respStringLen,echoBuffer);

        respCode = echoBuffer;

        /* Interpret server response */
        if (strcmp(respCode, "SUCCESS") == 0) {
            printf("Successfully cracked the password: %s\n", echoString);
        } else if (strcmp(respCode, "FAILURE") == 0) {
            //printf("Incorrect password: %s\n",echoString);
        } else
            printf("Unknown response code %s\n",respCode);
    }

    close(sock);
    end(0);
}

void generatePassword(char pass[], int N, int *index) {
    if (*index < 0) {
        memset(pass, '0', N+1);
        pass[N] = '\0';
        (*index)++;
    } else
        increment(pass, N, index);
}

void increment(char pass[], int N, int *index) {
    int i, overflow = 1;
    for (i = 0; i < N && overflow == 1 && i <= *index; i++) {
        char c = getNextChar(pass[i]);
        pass[i] = c;
        overflow = (c == '0') ? 1 : 0;
        if (overflow == 1 && i == (*index))
            (*index)++;
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

