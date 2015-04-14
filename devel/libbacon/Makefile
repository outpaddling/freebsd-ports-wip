# New ports collection makefile for:	libbacon
# Date created:		Nov 2006
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	libbacon
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Misc functions

CONFLICTS=	libbacon-1.[023456789]

PLIST_FILES=	lib/libbacon.a \
		include/bacon.h

USES=		tar:xz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
