# Created by: Jason Bacon <bacon@sculpin.acadix.biz>
# $FreeBSD$

PORTNAME=	openmvs
PORTVERSION=	0.7
DISTVERSIONPREFIX=v
CATEGORIES=	graphics

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open Multi-View Stereo reconstruction library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	cdcseacave
GH_PROJECT=	openMVS

BUILD_DEPENDS+=	eigen>3:math/eigen3 \
		${LOCALBASE}/lib/libceres.a:/usr/wip/math/ceres-solver \
		${LOCALBASE}/include/vcg/complex/algorithms/attribute_seam.h:/usr/wip/graphics/vcglib
LIB_DEPENDS+=	libopencv_objdetect.so:graphics/opencv \
		libCGAL.so:math/cgal \
		libboost_date_time.so:devel/boost-libs \
		libsysinfo.so:/usr/wip/devel/libsysinfo

CMAKE_ARGS+=	-DOpenMVS_USE_OPENMP:BOOL=off \
		-DOpenMVS_USE_CUDA:BOOK=off

# FIXME: This is being ignored by some link commands
LDFLAGS+=	-lsysinfo

WRKSRC=		${WRKDIR}/openMVS-${PORTVERSION}

CMAKE_VERBOSE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|#ifdef __APPLE__|#if defined(__APPLE__) \|\| defined(__FreeBSD__)|g' ${WRKSRC}/libs/Common/CriticalSection.h

.include <bsd.port.mk>
