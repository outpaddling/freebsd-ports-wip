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

USES=		tar:xz

BUILD_DEPENDS=	${LOCALBASE}/lib/libtwintk.a:/usr/wip/devel/twintk \
		${LOCALBASE}/lib/libbacon.a:/usr/wip/devel/libbacon \
		${LOCALBASE}/include/plasm-epc-bits.h:/usr/wip/devel/plasm
RUN_DEPENDS=	plasm:/usr/wip/devel/plasm

MAKE_ARGS=	CFLAGS="-O -I${LOCALBASE}/include"

INSTALL_TARGET=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX} \
		install

pre-build:
	make depend

.include <bsd.port.mk>
