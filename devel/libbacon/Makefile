# New ports collection makefile for:	libbacon
# Date created:		Nov 2006
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libbacon
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

CONFLICTS=	libbacon-1.[023456789]

PLIST_FILES=	lib/libbacon.a \
		include/bacon.h

USES=		tar:xz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
