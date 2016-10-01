# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/devel/openvex/Makefile 413746 2016-04-21 16:43:14Z swills $

PORTNAME=	openvex
PORTVERSION=	0.5.4
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open source firmware for Vex robotics controllers

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	sdcc:lang/sdcc \
		gpasm:devel/gputils
RUN_DEPENDS=	vexctl:devel/roboctl \
		sdcc:lang/sdcc \
		gpasm:devel/gputils

USES+=		tar:xz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

post-patch:
	@${REINPLACE_CMD} \
		-i '' -e 's|--denable-peeps|--denable-peeps --use-non-free|g' \
		${WRKSRC}/Include/Makefile.sdcc_defs

.include <bsd.port.mk>
