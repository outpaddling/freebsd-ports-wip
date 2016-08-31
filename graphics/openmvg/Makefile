# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	openMVG
PORTVERSION=	1.0
CATEGORIES=	graphics

MAINTAINER=	dsiercks@uwm.edu
COMMENT=

USE_GITHUB=	yes
GH_ACCOUNT=	openMVG
#GH_TAGNAME=	v${PORTVERSION}
GH_TAGNAME=	944254c
#DISTNAME=	v${PORTVERSION}

USES=		cmake:outsource
CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ENV=	EIGEN_INCLUDE_DIR_HINTS=/usr/local/include/eigen3 \
		CLP_INCLUDE_DIR_HINTS=/usr/local/include/coin \
		COINUTILS_DIR=/usr/local/include/coin/

BUILD_DEPENDS=	${NONEXISTENT}:math/eigen3 \
		${NONEXISTENT}:/usr/wip/math/ceres-solver

LIB_DEPENDS=	libpng.so:graphics/png \
		libjpeg.so:graphics/jpeg \
		libtiff.so:graphics/tiff \
		libXxf86vm.so:x11/libXxf86vm \
		libXi.so:x11/libXi \
		libXrandr.so:x11/libXrandr \
		libClp.so:math/clp \
		libCoinMP.so:math/coinmp
		
.include <bsd.port.mk>
