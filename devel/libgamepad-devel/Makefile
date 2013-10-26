# New ports collection makefile for:	libgamepad
# Date created:		Jul 2008
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD: ports/devel/libgamepad/Makefile,v 1.1 2008/07/26 07:55:02 edwin Exp $
#

PORTNAME=	libgamepad
PORTVERSION=	0.1.2
CATEGORIES=	devel games
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Generic gamepad API

pre-build:
	(cd ${WRKSRC} && make depend)

MAN3=		libgamepad.3

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
