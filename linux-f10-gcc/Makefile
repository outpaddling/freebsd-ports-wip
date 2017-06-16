# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.3.2
CATEGORIES=	wip devel linux
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	GNU Compiler Collection C compiler

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	7

# DEPENDS: binutils, binutils-devel
RUN_DEPENDS=	${LINUXBASE}/usr/bin/cpp:../../lang/linux-f10-cpp43 \
		${LINUXBASE}/usr/bin/as:../../devel/linux-f10-binutils \
		${LINUXBASE}/usr/include/ansidecl.h:../../devel/linux-f10-binutils-devel \
		${LINUXBASE}/lib/ld-2.9.so:../../devel/linux-f10-glibc \
		${LINUXBASE}/usr/bin/catchsegv:../../devel/linux-f10-glibc-common \
		${LINUXBASE}/usr/lib/Mcrt1.o:../../devel/linux-f10-glibc-devel \
		${LINUXBASE}/usr/include/_G_config.h:../../devel/linux-f10-glibc-headers \
		${LINUXBASE}/usr/lib/libgmp.so.3:../../devel/linux-f10-gmp \
		${LINUXBASE}/usr/lib/libmpfr.so.1:../../devel/linux-f10-mpfr \
		${LINUXBASE}/usr/include/linux/a.out.h:../../devel/linux-f10-kernel-headers

post-install:
	${RM} ${PREFIX}/usr/lib/gcc/i386-redhat-linux/4.3.2/libgcc_s.so
	${LN} -s /compat/linux/lib/libgcc_s.so.1 ${PREFIX}/usr/lib/gcc/i386-redhat-linux/4.3.2/libgcc_s.so

.include <bsd.port.mk>
