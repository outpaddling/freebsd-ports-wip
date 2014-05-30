# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: head/devel/libgamepad/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	libgamepad
PORTVERSION=	0.1.2
CATEGORIES=	devel games
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Generic gamepad API

pre-build:
	(cd ${WRKSRC} && make depend)

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
