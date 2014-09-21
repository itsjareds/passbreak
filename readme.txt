Package:  klinge2-hw1.tar.gz

Explanation:  


This package contains source code to two separate programs: A 
password breaker client and a password generating server. The
password server generates a random password in [0-9A-Za-z] and
waits for incoming connections to guess the correct password. If a
password guess is incorrect, the server responds with FAILURE. If
the password is guessed, the server responds with SUCCESS and 
generates a new password. If the client receives SUCCESS, it quits
and outputs guess statistics.


------------------------------------------------------------------
Design:


The design of the server is simple. It generates a random sequence
of characters by referring to an array of all possible characters.
Then, it selects from a random index in the array. The server waits
for incoming connections to guess the password, then it recreates
the password. A list of clients is generated in a list of Client
structs which contain IP address, number of attempts, and number
of successes for each client.

The client sets up a connection with the server, then loops forever
attempting new passwords until a SUCCESS message is received.

The client begins guessing with all zeroes, then increments. E.g.,
if N=4, the client goes on like this:

0000
1000
2000
....
z000
0100
1100
....
zzzx
zzzy
zzzz

The correct password should be in that range assuming the correct
N value was input.


------------------------------------------------------------------
Unpacking Instructions: 


Copy the klinge2-hw1.tar.gz package into a directory that you will use to
build and run the program from.  Issue the following commands:

$ gzip -d klinge2-hw1.tar.gz
$ tar -xf klinge2-hw1.tar

When done, you should see the following files:

DieWithError.c   Make.defines  Makefile  Makefile.bak  readme.txt
UDPEchoClient.c  UDPEcho.h     UDPEchoServer.c


------------------------------------------------------------------
Build Instructions:


When you download this package, issue the following to build:
$ make clean
$ make depend
$ make


------------------------------------------------------------------
Invocation:


./passwordServer <Server Port> <N> [<Initial Password>]
  -First parameter is the port the server will use.
  -Second parameter is the length of passwords to generate.
  -Third parameter is an initial password to use (optional).

./passwordBreaker <Server Name> <Server Port> <N>
  -First parameter is the server's IP address in dotted decimal format 
   or as a domain name.
  -Second parameter is the server's port number.
  -Third parameter is the length of the password to guess.

