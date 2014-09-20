#include "UDPEcho.h"


void DieWithError(char *errorMessage);  /* External error handling function */
void generatePassword(char pass[], const int len);  /* Password generation function */
void sendMessage(int sock, const char* message, size_t recvMsgSize,
                  const struct sockaddr *clientAddr, socklen_t addrLen);

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

    printf("UDPEchoServer: Using password %s\n", pass);

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

        /* Convert to a null-terminated string (don't care about bits past N-1) */
        echoBuffer[N] = '\0';

        /* Compare input to password */
        int equal = 0;
        if (recvMsgSize == N) {
            int i;
            for (i = 0; i < N; i++) {
                if (pass[i] != echoBuffer[i])
                    break;
                if (i + 1 == N)
                    equal = 1;
            }
        }
        if (equal) {
            /* Send SUCCESS to the client */
            printf("PASSWORD CRACKED! guess: %s  actual: %s\n", echoBuffer, pass);
            sendMessage(sock, "0", 2, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));
        } else {
            /* Send FAILURE to the client */
            printf("Incorrect! guess: %s  actual: %s\n", echoBuffer, pass);
            sendMessage(sock, "1", 2, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));
        }

        /* Send received datagram back to the client */
        sendMessage(sock, echoBuffer, recvMsgSize, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));
    }
    /* NOT REACHED */
}

void generatePassword(char pass[], const int N) {
    static char vals[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    if (pass == NULL)
        pass = (char*) malloc(sizeof(char)*N + 1);
    int i;
    for (i = 0; i < N; i++)
        pass[i] = vals[rand()%62];
    pass[i] = '\0';
}

void sendMessage(int sock, const char* message, size_t recvMsgSize,
                  const struct sockaddr *clientAddr, socklen_t addrLen) {
    int len = sendto(sock, message, recvMsgSize, 0, clientAddr, addrLen);
    printf("Sent message expected size=%zu, actual size=%d\n", recvMsgSize, len);
    if (len != recvMsgSize)
        DieWithError("sendto() sent a different number of bytes than expected");
}

