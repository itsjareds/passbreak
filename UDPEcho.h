/*********************************************************
*
* Module Name: UDP client/server header file
*
* Author: (provided file by S. Remy)
*
* File Name:    UDPEcho.h	
*
* Summary:
*  This file contains common stuff for the client and server
*
* Revisions:
*
* Methods:
*
*  void DieWithError(char *errorMessage):
*    o  errorMessage: Message to output before exit
*    Exits the program and prints an error message.
*
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>     /* for memset() */
#include <netinet/in.h> /* for in_addr */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <netdb.h>      /* for getHostByName() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <unistd.h>     /* for close() */
#include <time.h>       /* for seeding rand() */
#include <sys/time.h>   /* for gettimeofday() */

#define ECHOMAX 255     /* Longest string to echo */

void DieWithError(char *errorMessage);  /* External error handling function */

