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

#		Conflicts with jpeg-turbo, installed as a dep
#		libjpeg.so:graphics/jpeg
BUILD_DEPENDS=	eigen>0:math/eigen3 \
		ceres-solver>0:/usr/wip/math/ceres-solver \
		liblemon>0:/usr/wip/science/lemon
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libXxf86vm.so:x11/libXxf86vm \
		libXi.so:x11/libXi \
		libXrandr.so:x11/libXrandr \
		libClp.so:math/clp \

# Alternative to clp
#		libCoinMP.so:math/coinmp

USES=		cmake:outsource compiler:c++11-lang tar:xz
# USES=		cmake:outsource tar:xz
# FIXME: Hack in place of compiler:c++11-lang
# clang seg faults
# USE_GCC=	yes
# CXX=		clang++37

# http://stackoverflow.com/questions/26832199/getting-gcc-in-c11-mode-to-work-on-freebsd
# Use with gcc
# CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH \
		-D_GLIBCXX_USE_C99_MATH_TR1

CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ARGS+=	-DEIGEN_INCLUDE_DIR_HINTS:STRING=${LOCABASE}/include/eigen3 \
		-DCLP_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/coin \
		-DCOINUTILS_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/coin/ \
		-DOSI_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/coin \
		-DLEMON_INCLUDE_DIR_HINTS:STRING=${LOCALBASE}/include/lemon

# FIXME: Just for testing.  Remove if possible.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
