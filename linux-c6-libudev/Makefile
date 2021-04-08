PORTNAME=	libudev
PORTVERSION=	10.1
CATEGORIES=	wip sysutils linux
DISTFILES=	libudev-147-2.57.el6.i686.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	udev

ALWAYS_KEEP_DISTFILES=	YES

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-f10-dri-[0-9]* linux-dri-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	mesa-10.1.2-2.el6.src.rpm \
		libdrm-2.4.52-4.el6.src.rpm \
		freeglut-2.6.0-1.el6.src.rpm
.endif

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
#DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
