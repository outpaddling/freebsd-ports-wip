# Created by:	Jason Bacon
# $FreeBSD$

# http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/gcc-4.3.2-7.i386.rpm
# http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/gcc-c++-4.3.2-7.i386.rpm
# http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/gcc-gfortran-4.3.2-7.i386.rpm
# http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/gdb-6.8-29.fc10.i386.rpm
PORTNAME=	glibc-common
PORTVERSION=	2.9
CATEGORIES=	devel linux
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	GNU libc

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	2

# DEPENDS: binutils, binutils-devel

.include <bsd.port.mk>
