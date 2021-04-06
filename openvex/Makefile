
PORTNAME=	openvex
PORTVERSION=	0.5.4
CATEGORIES=	wip devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source firmware for Vex robotics controllers

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	sdcc2==2.9.0:wip/sdcc290 \
		gpasm:devel/gputils
RUN_DEPENDS=	vexctl:devel/roboctl \
		sdcc2==2.9.0:wip/sdcc290 \
		gpasm:devel/gputils

USES+=		tar:xz

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

post-patch:
	@${REINPLACE_CMD} \
		-i '' -e 's|--denable-peeps|--denable-peeps --use-non-free|g' \
		${WRKSRC}/Include/Makefile.sdcc_defs

.include <bsd.port.mk>
