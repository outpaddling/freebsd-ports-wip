# $FreeBSD: head/devel/openvex/Makefile 413746 2016-04-21 16:43:14Z swills $

PORTNAME=	openvex
PORTVERSION=	0.5.4
CATEGORIES=	wip devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source firmware for Vex robotics controllers

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	sdcc==2.9.0:wip/sdcc290 \
		gpasm:devel/gputils
RUN_DEPENDS=	vexctl:devel/roboctl \
		sdcc==2.9.0:wip/sdcc290 \
		gpasm:devel/gputils

USES+=		tar:xz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

post-patch:
	@${REINPLACE_CMD} \
		-i '' -e 's|--denable-peeps|--denable-peeps --use-non-free|g' \
		${WRKSRC}/Include/Makefile.sdcc_defs

.include <bsd.port.mk>
