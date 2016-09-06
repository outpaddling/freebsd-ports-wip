# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	openmvg
# FIXME: Hack around need for recursive git pull
PORTVERSION=	2016.09.06
CATEGORIES=	graphics
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Open Multiple View Geometry library

LICENSE=	MPL

#		libCoinMP.so:math/coinmp
BUILD_DEPENDS=	eigen>0:math/eigen3 \
		ceres-solver>0:/usr/wip/math/ceres-solver
LIB_DEPENDS=	libpng.so:graphics/png \
		libjpeg.so:graphics/jpeg \
		libtiff.so:graphics/tiff \
		libXxf86vm.so:x11/libXxf86vm \
		libXi.so:x11/libXi \
		libXrandr.so:x11/libXrandr \
		libClp.so:math/clp

# USES=		cmake:outsource compiler:c++11-lang tar:xz
USES=		cmake:outsource tar:xz
# FIXME: Hack in place of compiler:c++11-lang
USE_GCC=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ARGS+=	-DEIGEN_INCLUDE_DIR_HINTS:STRING=${LOCABASE}/include/eigen3 \
		-DCLP_INCLUDE_DIR_HINTS=${LOCALBASE}/include/coin \
		-DCOINUTILS_INCLUDE_DIR_HINTS=${LOCALBASE}/include/coin/

# FIXME: Just for testing.  Remove if possible.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
