# New ports collection makefile for:	libpare
# Date created:		Nov 2006
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libpare
PORTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Misc functions

USES=		tar:xz

PLIST_FILES=	lib/libpare.a \
		include/pare.h \
		man/man3/pare.3.gz

STRIP_CMD=

CFLAGS=		-g -Wall

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
