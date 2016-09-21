# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/devel/libsysinfo/Makefile 403506 2015-12-11 08:48:56Z miwi $

PORTNAME=	libsysinfo
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/sysinfo-bsd/libsysinfo-${PORTVERSION}.tar.gz

MAINTAINER=	bacon4000@gmail.com
COMMENT=	GNU libc's sysinfo port for FreeBSD

LICENSE=	BSD3CLAUSE

USES=		uidfix
USE_LDCONFIG=	yes
PROJECTHOST=	sysinfo-bsd

LDFLAGS+=	-lkvm

PLIST_FILES=	include/sys/sysinfo.h \
		lib/libsysinfo.a \
		lib/libsysinfo.so \
		lib/libsysinfo.so.0 \
		man/man3/sysinfo.3.gz
post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsysinfo.so.0

.include <bsd.port.mk>
