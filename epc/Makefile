# New ports collection makefile for:    plasm
# Date created:         2010-07-21
# Whom:                 Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	epc
PORTVERSION=	0.1
CATEGORIES=	wip emulators
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Educational Perrsonal Computer

USES=		tar:xz

BUILD_DEPENDS=	${LOCALBASE}/lib/libtwintk.a:wip/twintk \
		${LOCALBASE}/lib/libbacon.a:wip/libbacon \
		${LOCALBASE}/include/plasm-epc-bits.h:wip/plasm
RUN_DEPENDS=	plasm:wip/plasm

MAKE_ARGS=	CFLAGS="-O -I${LOCALBASE}/include"

INSTALL_TARGET=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX} \
		install

pre-build:
	make depend

.include <bsd.port.mk>
