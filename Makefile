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
		makedepend UDPEchoClient.c UDPEchoServer.c -I/usr/lib/gcc/x86_64-linux-gnu/4.6/include $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)
#		mkdep $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)

# DO NOT DELETE

UDPEchoClient.o: UDPEcho.h /usr/include/stdio.h /usr/include/sys/cdefs.h
UDPEchoClient.o: /usr/include/sys/_symbol_aliasing.h
UDPEchoClient.o: /usr/include/sys/_posix_availability.h
UDPEchoClient.o: /usr/include/Availability.h
UDPEchoClient.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
UDPEchoClient.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
UDPEchoClient.o: /usr/include/i386/_types.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_types.h
UDPEchoClient.o: /usr/include/sys/_types/_va_list.h
UDPEchoClient.o: /usr/include/sys/_types/_size_t.h
UDPEchoClient.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
UDPEchoClient.o: /usr/include/sys/_types/_off_t.h
UDPEchoClient.o: /usr/include/sys/_types/_ssize_t.h
UDPEchoClient.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
UDPEchoClient.o: /usr/include/stdlib.h /usr/include/sys/wait.h
UDPEchoClient.o: /usr/include/sys/_types/_pid_t.h
UDPEchoClient.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
UDPEchoClient.o: /usr/include/sys/appleapiopts.h
UDPEchoClient.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
UDPEchoClient.o: /usr/include/machine/_mcontext.h
UDPEchoClient.o: /usr/include/i386/_mcontext.h
UDPEchoClient.o: /usr/include/mach/i386/_structs.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_attr_t.h
UDPEchoClient.o: /usr/include/sys/_types/_sigaltstack.h
UDPEchoClient.o: /usr/include/sys/_types/_ucontext.h
UDPEchoClient.o: /usr/include/sys/_types/_sigset_t.h
UDPEchoClient.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
UDPEchoClient.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
UDPEchoClient.o: /usr/include/sys/_types/_int16_t.h
UDPEchoClient.o: /usr/include/sys/_types/_int32_t.h
UDPEchoClient.o: /usr/include/sys/_types/_int64_t.h
UDPEchoClient.o: /usr/include/_types/_uint8_t.h
UDPEchoClient.o: /usr/include/_types/_uint16_t.h
UDPEchoClient.o: /usr/include/_types/_uint32_t.h
UDPEchoClient.o: /usr/include/_types/_uint64_t.h
UDPEchoClient.o: /usr/include/sys/_types/_intptr_t.h
UDPEchoClient.o: /usr/include/sys/_types/_uintptr_t.h
UDPEchoClient.o: /usr/include/_types/_intmax_t.h
UDPEchoClient.o: /usr/include/_types/_uintmax_t.h
UDPEchoClient.o: /usr/include/sys/_types/_timeval.h
UDPEchoClient.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
UDPEchoClient.o: /usr/include/sys/_endian.h
UDPEchoClient.o: /usr/include/libkern/_OSByteOrder.h
UDPEchoClient.o: /usr/include/libkern/i386/_OSByteOrder.h
UDPEchoClient.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
UDPEchoClient.o: /usr/include/sys/_types/_rune_t.h
UDPEchoClient.o: /usr/include/sys/_types/_wchar_t.h
UDPEchoClient.o: /usr/include/machine/types.h /usr/include/i386/types.h
UDPEchoClient.o: /usr/include/sys/_types/_dev_t.h
UDPEchoClient.o: /usr/include/sys/_types/_mode_t.h /usr/include/errno.h
UDPEchoClient.o: /usr/include/sys/errno.h /usr/include/sys/_types/_errno_t.h
UDPEchoClient.o: /usr/include/sys/types.h /usr/include/sys/_types/_blkcnt_t.h
UDPEchoClient.o: /usr/include/sys/_types/_blksize_t.h
UDPEchoClient.o: /usr/include/sys/_types/_gid_t.h
UDPEchoClient.o: /usr/include/sys/_types/_in_addr_t.h
UDPEchoClient.o: /usr/include/sys/_types/_in_port_t.h
UDPEchoClient.o: /usr/include/sys/_types/_ino_t.h
UDPEchoClient.o: /usr/include/sys/_types/_ino64_t.h
UDPEchoClient.o: /usr/include/sys/_types/_key_t.h
UDPEchoClient.o: /usr/include/sys/_types/_nlink_t.h
UDPEchoClient.o: /usr/include/sys/_types/_clock_t.h
UDPEchoClient.o: /usr/include/sys/_types/_time_t.h
UDPEchoClient.o: /usr/include/sys/_types/_useconds_t.h
UDPEchoClient.o: /usr/include/sys/_types/_suseconds_t.h
UDPEchoClient.o: /usr/include/sys/_types/_rsize_t.h
UDPEchoClient.o: /usr/include/sys/_types/_fd_def.h
UDPEchoClient.o: /usr/include/sys/_types/_fd_setsize.h
UDPEchoClient.o: /usr/include/sys/_types/_fd_set.h
UDPEchoClient.o: /usr/include/sys/_types/_fd_clr.h
UDPEchoClient.o: /usr/include/sys/_types/_fd_zero.h
UDPEchoClient.o: /usr/include/sys/_types/_fd_isset.h
UDPEchoClient.o: /usr/include/sys/_types/_fd_copy.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_cond_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_once_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_t.h
UDPEchoClient.o: /usr/include/sys/_pthread/_pthread_key_t.h
UDPEchoClient.o: /usr/include/sys/_types/_fsblkcnt_t.h
UDPEchoClient.o: /usr/include/sys/_types/_fsfilcnt_t.h /usr/include/string.h
UDPEchoClient.o: /usr/include/strings.h /usr/include/secure/_string.h
UDPEchoClient.o: /usr/include/netinet/in.h /usr/include/sys/socket.h
UDPEchoClient.o: /usr/include/machine/_param.h /usr/include/i386/_param.h
UDPEchoClient.o: /usr/include/sys/_types/_sa_family_t.h
UDPEchoClient.o: /usr/include/sys/_types/_socklen_t.h
UDPEchoClient.o: /usr/include/sys/_types/_iovec_t.h
UDPEchoClient.o: /usr/include/netinet6/in6.h /usr/include/arpa/inet.h
UDPEchoClient.o: /usr/include/netdb.h /usr/include/unistd.h
UDPEchoClient.o: /usr/include/sys/unistd.h
UDPEchoClient.o: /usr/include/sys/_types/_posix_vdisable.h
UDPEchoClient.o: /usr/include/sys/_types/_seek_set.h
UDPEchoClient.o: /usr/include/sys/select.h
UDPEchoClient.o: /usr/include/sys/_types/_timespec.h
UDPEchoClient.o: /usr/include/sys/_select.h /usr/include/sys/_types/_uuid_t.h
UDPEchoClient.o: /usr/include/gethostuuid.h /usr/include/time.h
UDPEchoClient.o: /usr/include/sys/time.h /usr/include/signal.h
UDPEchoServer.o: UDPEcho.h /usr/include/stdio.h /usr/include/sys/cdefs.h
UDPEchoServer.o: /usr/include/sys/_symbol_aliasing.h
UDPEchoServer.o: /usr/include/sys/_posix_availability.h
UDPEchoServer.o: /usr/include/Availability.h
UDPEchoServer.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
UDPEchoServer.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
UDPEchoServer.o: /usr/include/i386/_types.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_types.h
UDPEchoServer.o: /usr/include/sys/_types/_va_list.h
UDPEchoServer.o: /usr/include/sys/_types/_size_t.h
UDPEchoServer.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
UDPEchoServer.o: /usr/include/sys/_types/_off_t.h
UDPEchoServer.o: /usr/include/sys/_types/_ssize_t.h
UDPEchoServer.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
UDPEchoServer.o: /usr/include/stdlib.h /usr/include/sys/wait.h
UDPEchoServer.o: /usr/include/sys/_types/_pid_t.h
UDPEchoServer.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
UDPEchoServer.o: /usr/include/sys/appleapiopts.h
UDPEchoServer.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
UDPEchoServer.o: /usr/include/machine/_mcontext.h
UDPEchoServer.o: /usr/include/i386/_mcontext.h
UDPEchoServer.o: /usr/include/mach/i386/_structs.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_attr_t.h
UDPEchoServer.o: /usr/include/sys/_types/_sigaltstack.h
UDPEchoServer.o: /usr/include/sys/_types/_ucontext.h
UDPEchoServer.o: /usr/include/sys/_types/_sigset_t.h
UDPEchoServer.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
UDPEchoServer.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
UDPEchoServer.o: /usr/include/sys/_types/_int16_t.h
UDPEchoServer.o: /usr/include/sys/_types/_int32_t.h
UDPEchoServer.o: /usr/include/sys/_types/_int64_t.h
UDPEchoServer.o: /usr/include/_types/_uint8_t.h
UDPEchoServer.o: /usr/include/_types/_uint16_t.h
UDPEchoServer.o: /usr/include/_types/_uint32_t.h
UDPEchoServer.o: /usr/include/_types/_uint64_t.h
UDPEchoServer.o: /usr/include/sys/_types/_intptr_t.h
UDPEchoServer.o: /usr/include/sys/_types/_uintptr_t.h
UDPEchoServer.o: /usr/include/_types/_intmax_t.h
UDPEchoServer.o: /usr/include/_types/_uintmax_t.h
UDPEchoServer.o: /usr/include/sys/_types/_timeval.h
UDPEchoServer.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
UDPEchoServer.o: /usr/include/sys/_endian.h
UDPEchoServer.o: /usr/include/libkern/_OSByteOrder.h
UDPEchoServer.o: /usr/include/libkern/i386/_OSByteOrder.h
UDPEchoServer.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
UDPEchoServer.o: /usr/include/sys/_types/_rune_t.h
UDPEchoServer.o: /usr/include/sys/_types/_wchar_t.h
UDPEchoServer.o: /usr/include/machine/types.h /usr/include/i386/types.h
UDPEchoServer.o: /usr/include/sys/_types/_dev_t.h
UDPEchoServer.o: /usr/include/sys/_types/_mode_t.h /usr/include/errno.h
UDPEchoServer.o: /usr/include/sys/errno.h /usr/include/sys/_types/_errno_t.h
UDPEchoServer.o: /usr/include/sys/types.h /usr/include/sys/_types/_blkcnt_t.h
UDPEchoServer.o: /usr/include/sys/_types/_blksize_t.h
UDPEchoServer.o: /usr/include/sys/_types/_gid_t.h
UDPEchoServer.o: /usr/include/sys/_types/_in_addr_t.h
UDPEchoServer.o: /usr/include/sys/_types/_in_port_t.h
UDPEchoServer.o: /usr/include/sys/_types/_ino_t.h
UDPEchoServer.o: /usr/include/sys/_types/_ino64_t.h
UDPEchoServer.o: /usr/include/sys/_types/_key_t.h
UDPEchoServer.o: /usr/include/sys/_types/_nlink_t.h
UDPEchoServer.o: /usr/include/sys/_types/_clock_t.h
UDPEchoServer.o: /usr/include/sys/_types/_time_t.h
UDPEchoServer.o: /usr/include/sys/_types/_useconds_t.h
UDPEchoServer.o: /usr/include/sys/_types/_suseconds_t.h
UDPEchoServer.o: /usr/include/sys/_types/_rsize_t.h
UDPEchoServer.o: /usr/include/sys/_types/_fd_def.h
UDPEchoServer.o: /usr/include/sys/_types/_fd_setsize.h
UDPEchoServer.o: /usr/include/sys/_types/_fd_set.h
UDPEchoServer.o: /usr/include/sys/_types/_fd_clr.h
UDPEchoServer.o: /usr/include/sys/_types/_fd_zero.h
UDPEchoServer.o: /usr/include/sys/_types/_fd_isset.h
UDPEchoServer.o: /usr/include/sys/_types/_fd_copy.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_cond_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_once_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_t.h
UDPEchoServer.o: /usr/include/sys/_pthread/_pthread_key_t.h
UDPEchoServer.o: /usr/include/sys/_types/_fsblkcnt_t.h
UDPEchoServer.o: /usr/include/sys/_types/_fsfilcnt_t.h /usr/include/string.h
UDPEchoServer.o: /usr/include/strings.h /usr/include/secure/_string.h
UDPEchoServer.o: /usr/include/netinet/in.h /usr/include/sys/socket.h
UDPEchoServer.o: /usr/include/machine/_param.h /usr/include/i386/_param.h
UDPEchoServer.o: /usr/include/sys/_types/_sa_family_t.h
UDPEchoServer.o: /usr/include/sys/_types/_socklen_t.h
UDPEchoServer.o: /usr/include/sys/_types/_iovec_t.h
UDPEchoServer.o: /usr/include/netinet6/in6.h /usr/include/arpa/inet.h
UDPEchoServer.o: /usr/include/netdb.h /usr/include/unistd.h
UDPEchoServer.o: /usr/include/sys/unistd.h
UDPEchoServer.o: /usr/include/sys/_types/_posix_vdisable.h
UDPEchoServer.o: /usr/include/sys/_types/_seek_set.h
UDPEchoServer.o: /usr/include/sys/select.h
UDPEchoServer.o: /usr/include/sys/_types/_timespec.h
UDPEchoServer.o: /usr/include/sys/_select.h /usr/include/sys/_types/_uuid_t.h
UDPEchoServer.o: /usr/include/gethostuuid.h /usr/include/time.h
UDPEchoServer.o: /usr/include/sys/time.h /usr/include/signal.h
DieWithError.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
DieWithError.o: /usr/include/sys/_symbol_aliasing.h
DieWithError.o: /usr/include/sys/_posix_availability.h
DieWithError.o: /usr/include/Availability.h
DieWithError.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
DieWithError.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
DieWithError.o: /usr/include/i386/_types.h
DieWithError.o: /usr/include/sys/_pthread/_pthread_types.h
DieWithError.o: /usr/include/sys/_types/_va_list.h
DieWithError.o: /usr/include/sys/_types/_size_t.h
DieWithError.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
DieWithError.o: /usr/include/sys/_types/_off_t.h
DieWithError.o: /usr/include/sys/_types/_ssize_t.h
DieWithError.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
DieWithError.o: /usr/include/stdlib.h /usr/include/sys/wait.h
DieWithError.o: /usr/include/sys/_types/_pid_t.h
DieWithError.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
DieWithError.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
DieWithError.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
DieWithError.o: /usr/include/i386/_mcontext.h
DieWithError.o: /usr/include/mach/i386/_structs.h
DieWithError.o: /usr/include/sys/_pthread/_pthread_attr_t.h
DieWithError.o: /usr/include/sys/_types/_sigaltstack.h
DieWithError.o: /usr/include/sys/_types/_ucontext.h
DieWithError.o: /usr/include/sys/_types/_sigset_t.h
DieWithError.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
DieWithError.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
DieWithError.o: /usr/include/sys/_types/_int16_t.h
DieWithError.o: /usr/include/sys/_types/_int32_t.h
DieWithError.o: /usr/include/sys/_types/_int64_t.h
DieWithError.o: /usr/include/_types/_uint8_t.h
DieWithError.o: /usr/include/_types/_uint16_t.h
DieWithError.o: /usr/include/_types/_uint32_t.h
DieWithError.o: /usr/include/_types/_uint64_t.h
DieWithError.o: /usr/include/sys/_types/_intptr_t.h
DieWithError.o: /usr/include/sys/_types/_uintptr_t.h
DieWithError.o: /usr/include/_types/_intmax_t.h
DieWithError.o: /usr/include/_types/_uintmax_t.h
DieWithError.o: /usr/include/sys/_types/_timeval.h
DieWithError.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
DieWithError.o: /usr/include/sys/_endian.h
DieWithError.o: /usr/include/libkern/_OSByteOrder.h
DieWithError.o: /usr/include/libkern/i386/_OSByteOrder.h
DieWithError.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
DieWithError.o: /usr/include/sys/_types/_rune_t.h
DieWithError.o: /usr/include/sys/_types/_wchar_t.h
DieWithError.o: /usr/include/machine/types.h /usr/include/i386/types.h
DieWithError.o: /usr/include/sys/_types/_dev_t.h
DieWithError.o: /usr/include/sys/_types/_mode_t.h
