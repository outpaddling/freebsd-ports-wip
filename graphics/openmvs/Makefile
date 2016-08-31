# Created by: Jason Bacon <bacon@sculpin.acadix.biz>
# $FreeBSD$

PORTNAME=	openmvs
PORTVERSION=	0.7
DISTVERSIONPREFIX=v
#DISTNAME=v
CATEGORIES=	graphics

MAINTAINER=	bacon@sculpin.acadix.biz
COMMENT=	Open Multi-View Stereo reconstruction library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:openmp

USE_GITHUB=	yes
GH_ACCOUNT=	cdcseacave
GH_PROJECT=	openMVS

BUILD_DEPENDS+=	eigen>3:math/eigen3 \
		${LOCALBASE}/lib/libceres.a:/usr/wip/math/ceres-solver \
		${LOCALBASE}/include/vcg/complex/algorithms/attribute_seam.h:/usr/wip/graphics/vcglib
LIB_DEPENDS+=	libopencv_objdetect.so:graphics/opencv \
		libCGAL.so:math/cgal \
		libboost_date_time.so:devel/boost-libs

WRKSRC=		${WRKDIR}/openMVS-${PORTVERSION}

.include <bsd.port.mk>
