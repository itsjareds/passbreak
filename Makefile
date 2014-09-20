include Make.defines

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
		makedepend UDPEchoClient.c UDPEchoServer.c  $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)
#		mkdep $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)

# DO NOT DELETE

UDPEchoClient.o: UDPEcho.h /usr/include/stdio.h /usr/include/features.h
UDPEchoClient.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
UDPEchoClient.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
UDPEchoClient.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
UDPEchoClient.o: /usr/include/bits/typesizes.h /usr/include/libio.h
UDPEchoClient.o: /usr/include/_G_config.h /usr/include/wchar.h
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
UDPEchoClient.o: /usr/include/stdint.h /usr/include/bits/wchar.h
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
UDPEchoClient.o: /usr/include/signal.h /usr/include/bits/signum.h
UDPEchoClient.o: /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h
UDPEchoClient.o: /usr/include/bits/sigcontext.h /usr/include/bits/sigstack.h
UDPEchoClient.o: /usr/include/sys/ucontext.h /usr/include/bits/sigthread.h
UDPEchoServer.o: UDPEcho.h /usr/include/stdio.h /usr/include/features.h
UDPEchoServer.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
UDPEchoServer.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
UDPEchoServer.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
UDPEchoServer.o: /usr/include/bits/typesizes.h /usr/include/libio.h
UDPEchoServer.o: /usr/include/_G_config.h /usr/include/wchar.h
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
UDPEchoServer.o: /usr/include/stdint.h /usr/include/bits/wchar.h
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
DieWithError.o: /usr/include/stdio.h /usr/include/features.h
DieWithError.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
DieWithError.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
DieWithError.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
DieWithError.o: /usr/include/bits/typesizes.h /usr/include/libio.h
DieWithError.o: /usr/include/_G_config.h /usr/include/wchar.h
DieWithError.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
DieWithError.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
DieWithError.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
DieWithError.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
DieWithError.o: /usr/include/sys/types.h /usr/include/time.h
DieWithError.o: /usr/include/sys/select.h /usr/include/bits/select.h
DieWithError.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
DieWithError.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
DieWithError.o: /usr/include/alloca.h
