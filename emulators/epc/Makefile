# New ports collection makefile for:    plasm
# Date created:         2010-07-21
# Whom:                 Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	epc
PORTVERSION=	0.1
CATEGORIES=	emulators
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Educational Perrsonal Computer

BUILD_DEPENDS=	${LOCALBASE}/lib/libtwintk.a:../../devel/twintk \
		${LOCALBASE}/lib/libbacon.a:../../devel/libbacon
RUN_DEPENDS=	asepc:../../devel/plasm

MAKE_ARGS=	CFLAGS="-O -I${LOCALBASE}/include"

MAN1=		epc.1

pre-build:
	make depend

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
