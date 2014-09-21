Make.defines                                                                                        0000600 0647422 0023420 00000000642 12407140370 012717  0                                                                                                    ustar   klinge2                         cuuser                                                                                                                                                                                                                 #Select your environment

# for BSD
#OSFLAG = -DBSD
#LIBS = 
#LINKFLAGS  =

# for SOLARIS
#OSFLAG = -DSOLARIS
#LIBS = 
#LINKFLAGS = -lsocket -lnsl
# for Linux
OSFLAG = -DLINUX
LIBS = 
LINKFLAGS =



LINKOPTIONS = -o


CC = gcc
CFLAGS = -c -ggdb -O2 -Wall $(OSFLAG)
CPLUS = g++
CPLUSFLAGS = -c -ggdb -O2 -Wall $(OSFLAG)


CLEANFILES = core core.* *.core *.o temp.* *.out typescript* \
		*.lc *.lh *.bsdi *.sparc *.uw


                                                                                              Makefile                                                                                            0000600 0647422 0023420 00000016514 12407626271 012161  0                                                                                                    ustar   klinge2                         cuuser                                                                                                                                                                                                                 include Make.defines

PROGS =	 passwordBreaker passwordServer

OPTIONS = -DUNIX  -DUSE_SIGACTION -DANSI


COBJECTS =	DieWithError.o 
CSOURCES =	DieWithError.c 

CPLUSOBJECTS = 

COMMONSOURCES =

CPLUSSOURCES =

all:	${PROGS}


passwordBreaker:	UDPEchoClient.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(COMMONSOURCES) $(SOURCES)
		${CC} ${LINKOPTIONS}  $@ UDPEchoClient.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(LINKFLAGS)


passwordServer:		UDPEchoServer.o $(CPLUSOBJECTS) $(COBJECTS)
		${CC} ${LINKOPTIONS} $@ UDPEchoServer.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(LINKFLAGS)


.cc.o:	$(HEADERS)
	$(CPLUS) $(CPLUSFLAGS) $(OPTIONS) $<

.c.o:	$(HEADERS)
	$(CC) $(CFLAGS) $(OPTIONS) $<



backup:
	rm -f UDPEcho.tar.gz
	tar -cf UDPEcho.tar *
	gzip -f UDPEcho.tar

clean:
		rm -f ${PROGS} ${CLEANFILES}

depend:
		makedepend UDPEchoClient.c UDPEchoServer.c -I/usr/lib/gcc/x86_64-linux-gnu/4.6/include $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)
#		mkdep $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)

# DO NOT DELETE

UDPEchoClient.o: UDPEcho.h /usr/include/stdio.h /usr/include/features.h
UDPEchoClient.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
UDPEchoClient.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
UDPEchoClient.o: /usr/include/gnu/stubs-64.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
UDPEchoClient.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
UDPEchoClient.o: /usr/include/libio.h /usr/include/_G_config.h
UDPEchoClient.o: /usr/include/wchar.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
UDPEchoClient.o: /usr/include/bits/stdio_lim.h
UDPEchoClient.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
UDPEchoClient.o: /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h
UDPEchoClient.o: /usr/include/endian.h /usr/include/bits/endian.h
UDPEchoClient.o: /usr/include/bits/byteswap.h /usr/include/sys/types.h
UDPEchoClient.o: /usr/include/time.h /usr/include/sys/select.h
UDPEchoClient.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
UDPEchoClient.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
UDPEchoClient.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
UDPEchoClient.o: /usr/include/errno.h /usr/include/bits/errno.h
UDPEchoClient.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
UDPEchoClient.o: /usr/include/asm-generic/errno.h
UDPEchoClient.o: /usr/include/asm-generic/errno-base.h /usr/include/string.h
UDPEchoClient.o: /usr/include/xlocale.h /usr/include/netinet/in.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint-gcc.h
UDPEchoClient.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
UDPEchoClient.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
UDPEchoClient.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
UDPEchoClient.o: /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h
UDPEchoClient.o: /usr/include/asm-generic/sockios.h /usr/include/bits/in.h
UDPEchoClient.o: /usr/include/arpa/inet.h /usr/include/netdb.h
UDPEchoClient.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
UDPEchoClient.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
UDPEchoClient.o: /usr/include/bits/environments.h
UDPEchoClient.o: /usr/include/bits/confname.h /usr/include/getopt.h
UDPEchoClient.o: /usr/include/sys/time.h /usr/include/signal.h
UDPEchoClient.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
UDPEchoClient.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
UDPEchoClient.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
UDPEchoClient.o: /usr/include/bits/sigthread.h
UDPEchoServer.o: UDPEcho.h /usr/include/stdio.h /usr/include/features.h
UDPEchoServer.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
UDPEchoServer.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
UDPEchoServer.o: /usr/include/gnu/stubs-64.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
UDPEchoServer.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
UDPEchoServer.o: /usr/include/libio.h /usr/include/_G_config.h
UDPEchoServer.o: /usr/include/wchar.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
UDPEchoServer.o: /usr/include/bits/stdio_lim.h
UDPEchoServer.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
UDPEchoServer.o: /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h
UDPEchoServer.o: /usr/include/endian.h /usr/include/bits/endian.h
UDPEchoServer.o: /usr/include/bits/byteswap.h /usr/include/sys/types.h
UDPEchoServer.o: /usr/include/time.h /usr/include/sys/select.h
UDPEchoServer.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
UDPEchoServer.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
UDPEchoServer.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
UDPEchoServer.o: /usr/include/errno.h /usr/include/bits/errno.h
UDPEchoServer.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
UDPEchoServer.o: /usr/include/asm-generic/errno.h
UDPEchoServer.o: /usr/include/asm-generic/errno-base.h /usr/include/string.h
UDPEchoServer.o: /usr/include/xlocale.h /usr/include/netinet/in.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint-gcc.h
UDPEchoServer.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
UDPEchoServer.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
UDPEchoServer.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
UDPEchoServer.o: /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h
UDPEchoServer.o: /usr/include/asm-generic/sockios.h /usr/include/bits/in.h
UDPEchoServer.o: /usr/include/arpa/inet.h /usr/include/netdb.h
UDPEchoServer.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
UDPEchoServer.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
UDPEchoServer.o: /usr/include/bits/environments.h
UDPEchoServer.o: /usr/include/bits/confname.h /usr/include/getopt.h
UDPEchoServer.o: /usr/include/sys/time.h /usr/include/signal.h
UDPEchoServer.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
UDPEchoServer.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
UDPEchoServer.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
UDPEchoServer.o: /usr/include/bits/sigthread.h
DieWithError.o: /usr/include/stdio.h /usr/include/features.h
DieWithError.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
DieWithError.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
DieWithError.o: /usr/include/gnu/stubs-64.h
DieWithError.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
DieWithError.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
DieWithError.o: /usr/include/libio.h /usr/include/_G_config.h
DieWithError.o: /usr/include/wchar.h
DieWithError.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
DieWithError.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
DieWithError.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
DieWithError.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
DieWithError.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
DieWithError.o: /usr/include/sys/types.h /usr/include/time.h
DieWithError.o: /usr/include/sys/select.h /usr/include/bits/select.h
DieWithError.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
DieWithError.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
DieWithError.o: /usr/include/alloca.h
                                                                                                                                                                                    Makefile.bak                                                                                        0000600 0647422 0023420 00000016514 12407626232 012712  0                                                                                                    ustar   klinge2                         cuuser                                                                                                                                                                                                                 include Make.defines

PROGS =	 passwordBreaker passwordServer

OPTIONS = -DUNIX  -DUSE_SIGACTION -DANSI


COBJECTS =	DieWithError.o 
CSOURCES =	DieWithError.c 

CPLUSOBJECTS = 

COMMONSOURCES =

CPLUSSOURCES =

all:	${PROGS}


passwordBreaker:	UDPEchoClient.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(COMMONSOURCES) $(SOURCES)
		${CC} ${LINKOPTIONS}  $@ UDPEchoClient.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(LINKFLAGS)


passwordServer:		UDPEchoServer.o $(CPLUSOBJECTS) $(COBJECTS)
		${CC} ${LINKOPTIONS} $@ UDPEchoServer.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(LINKFLAGS)


.cc.o:	$(HEADERS)
	$(CPLUS) $(CPLUSFLAGS) $(OPTIONS) $<

.c.o:	$(HEADERS)
	$(CC) $(CFLAGS) $(OPTIONS) $<



backup:
	rm -f UDPEcho.tar.gz
	tar -cf UDPEcho.tar *
	gzip -f UDPEcho.tar

clean:
		rm -f ${PROGS} ${CLEANFILES}

depend:
		makedepend UDPEchoClient.c UDPEchoServer.c -I/usr/lib/gcc/x86_64-linux-gnu/4.6/include $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)
#		mkdep $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)

# DO NOT DELETE

UDPEchoClient.o: UDPEcho.h /usr/include/stdio.h /usr/include/features.h
UDPEchoClient.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
UDPEchoClient.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
UDPEchoClient.o: /usr/include/gnu/stubs-64.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
UDPEchoClient.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
UDPEchoClient.o: /usr/include/libio.h /usr/include/_G_config.h
UDPEchoClient.o: /usr/include/wchar.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
UDPEchoClient.o: /usr/include/bits/stdio_lim.h
UDPEchoClient.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
UDPEchoClient.o: /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h
UDPEchoClient.o: /usr/include/endian.h /usr/include/bits/endian.h
UDPEchoClient.o: /usr/include/bits/byteswap.h /usr/include/sys/types.h
UDPEchoClient.o: /usr/include/time.h /usr/include/sys/select.h
UDPEchoClient.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
UDPEchoClient.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
UDPEchoClient.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
UDPEchoClient.o: /usr/include/errno.h /usr/include/bits/errno.h
UDPEchoClient.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
UDPEchoClient.o: /usr/include/asm-generic/errno.h
UDPEchoClient.o: /usr/include/asm-generic/errno-base.h /usr/include/string.h
UDPEchoClient.o: /usr/include/xlocale.h /usr/include/netinet/in.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint.h
UDPEchoClient.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint-gcc.h
UDPEchoClient.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
UDPEchoClient.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
UDPEchoClient.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
UDPEchoClient.o: /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h
UDPEchoClient.o: /usr/include/asm-generic/sockios.h /usr/include/bits/in.h
UDPEchoClient.o: /usr/include/arpa/inet.h /usr/include/netdb.h
UDPEchoClient.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
UDPEchoClient.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
UDPEchoClient.o: /usr/include/bits/environments.h
UDPEchoClient.o: /usr/include/bits/confname.h /usr/include/getopt.h
UDPEchoClient.o: /usr/include/sys/time.h /usr/include/signal.h
UDPEchoClient.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
UDPEchoClient.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
UDPEchoClient.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
UDPEchoClient.o: /usr/include/bits/sigthread.h
UDPEchoServer.o: UDPEcho.h /usr/include/stdio.h /usr/include/features.h
UDPEchoServer.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
UDPEchoServer.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
UDPEchoServer.o: /usr/include/gnu/stubs-64.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
UDPEchoServer.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
UDPEchoServer.o: /usr/include/libio.h /usr/include/_G_config.h
UDPEchoServer.o: /usr/include/wchar.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
UDPEchoServer.o: /usr/include/bits/stdio_lim.h
UDPEchoServer.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
UDPEchoServer.o: /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h
UDPEchoServer.o: /usr/include/endian.h /usr/include/bits/endian.h
UDPEchoServer.o: /usr/include/bits/byteswap.h /usr/include/sys/types.h
UDPEchoServer.o: /usr/include/time.h /usr/include/sys/select.h
UDPEchoServer.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
UDPEchoServer.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
UDPEchoServer.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
UDPEchoServer.o: /usr/include/errno.h /usr/include/bits/errno.h
UDPEchoServer.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
UDPEchoServer.o: /usr/include/asm-generic/errno.h
UDPEchoServer.o: /usr/include/asm-generic/errno-base.h /usr/include/string.h
UDPEchoServer.o: /usr/include/xlocale.h /usr/include/netinet/in.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint.h
UDPEchoServer.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint-gcc.h
UDPEchoServer.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
UDPEchoServer.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
UDPEchoServer.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
UDPEchoServer.o: /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h
UDPEchoServer.o: /usr/include/asm-generic/sockios.h /usr/include/bits/in.h
UDPEchoServer.o: /usr/include/arpa/inet.h /usr/include/netdb.h
UDPEchoServer.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
UDPEchoServer.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
UDPEchoServer.o: /usr/include/bits/environments.h
UDPEchoServer.o: /usr/include/bits/confname.h /usr/include/getopt.h
UDPEchoServer.o: /usr/include/sys/time.h /usr/include/signal.h
UDPEchoServer.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
UDPEchoServer.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
UDPEchoServer.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
UDPEchoServer.o: /usr/include/bits/sigthread.h
DieWithError.o: /usr/include/stdio.h /usr/include/features.h
DieWithError.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
DieWithError.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
DieWithError.o: /usr/include/gnu/stubs-64.h
DieWithError.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
DieWithError.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
DieWithError.o: /usr/include/libio.h /usr/include/_G_config.h
DieWithError.o: /usr/include/wchar.h
DieWithError.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
DieWithError.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
DieWithError.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
DieWithError.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
DieWithError.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
DieWithError.o: /usr/include/sys/types.h /usr/include/time.h
DieWithError.o: /usr/include/sys/select.h /usr/include/bits/select.h
DieWithError.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
DieWithError.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
DieWithError.o: /usr/include/alloca.h
                                                                                                                                                                                    readme.txt                                                                                          0000600 0647422 0023420 00000005074 12407630357 012516  0                                                                                                    ustar   klinge2                         cuuser                                                                                                                                                                                                                 Package:  klinge2-hw1.tar.gz

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

                                                                                                                                                                                                                                                                                                                                                                                                                                                                    UDPEchoClient.c                                                                                     0000600 0647422 0023420 00000014466 12407625667 013267  0                                                                                                    ustar   klinge2                         cuuser                                                                                                                                                                                                                 /*********************************************************
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

                                                                                                                                                                                                          UDPEcho.h                                                                                           0000600 0647422 0023420 00000002222 12407626150 012104  0                                                                                                    ustar   klinge2                         cuuser                                                                                                                                                                                                                 /*********************************************************
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

                                                                                                                                                                                                                                                                                                                                                                              UDPEchoServer.c                                                                                     0000600 0647422 0023420 00000020510 12407625673 013277  0                                                                                                    ustar   klinge2                         cuuser                                                                                                                                                                                                                 /***************************************************************
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

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        