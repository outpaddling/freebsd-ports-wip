LIB		= sysinfo
LIBDIR		= ${PREFIX}/lib/
INCLUDEDIR 	= ${PREFIX}/include/sys/
MANDIR		= ${PREFIX}/man/man3
SHLIB_MAJOR	= 0
WITHOUT_PROFILE = yes
MAKEOBJDIRPREFIX= /

SRCS	= sysinfo.c

CFLAGS	+= -Iinclude

DEBUG_FLAGS	= -ggdb
WARNS		?= 0

.include <bsd.lib.mk>

install:
	@if [ -d ${INCLUDEDIR} ]; then else mkdir ${INCLUDEDIR}; fi
	@if [ -d ${MANDIR} ]; then else mkdir ${MANDIR}; fi
	install -c -m 0444 ${.CURDIR}/include/sys/sysinfo.h  ${INCLUDEDIR}
	install -c -m 0444 ${.CURDIR}/man/sysinfo.3 ${MANDIR}
