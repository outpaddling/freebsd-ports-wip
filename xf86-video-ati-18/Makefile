PORTNAME=	xf86-video-ati
PORTVERSION=	18.1.0
PORTEPOCH=	1
CATEGORIES=	wip x11-drivers
PKGNAMESUFFIX=	-18

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

# No Radeon kernel driver on non-x86.
ONLY_FOR_ARCHS=		amd64 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libdrm_radeon.so:graphics/libdrm

CONFLICTS_INSTALL=	xf86-video-ati-legacy

USES=		gl
USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	pciaccess

CONFIGURE_ARGS+=--disable-udev

.include <bsd.port.mk>
