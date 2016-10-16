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

BUILD_DEPENDS=	eigen>=3:math/eigen3 \
		ceres-solver>0:math/ceres-solver \
		liblemon>0:/usr/wip/science/liblemon \
		flann>0:/usr/wip/science/flann
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libXxf86vm.so:x11/libXxf86vm \
		libXi.so:x11/libXi \
		libXrandr.so:x11/libXrandr \
		libClp.so:math/clp \
		libglog.so:devel/glog

# Alternative to clp
# FIXME: Will try to link to coinmp if present. Installed as a libreoffice dep.
#		libCoinMP.so:math/coinmp \

USES=		cmake:outsource compiler:c++11-lang fortran jpeg tar:xz

CXXFLAGS+=	-Wno-deprecated-register
LDFLAGS+=	-L${LOCALBASE}/lib/gcc48 -lgfortran

CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ARGS+=	-DEIGEN_INCLUDE_DIR_HINTS:STRING=${LOCABASE}/include/eigen3 \
		-DCLP_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/coin \
		-DCOINUTILS_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/coin/ \
		-DOSI_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/coin \
		-DLEMON_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/lemon \
		-DFLANN_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/flann

# Compiler flag optimizer crashes clang and can't be used for package
# building anyway.
post-patch:
	${REINPLACE_CMD} \
		-e '/OptimizeForArchitecture/d' \
		-e 's|-O3|-O2|g' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
