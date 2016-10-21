# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	caffe
PORTVERSION=	2016.10.20
CATEGORIES=	science

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	Fast open framework for deep learning

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy
LIB_DEPENDS+=	libboost_regex.so:devel/boost-libs \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libhdf5.so:science/hdf5 \
		liblmdb.so:databases/lmdb \
		libleveldb.so:databases/leveldb \
		libopenblasp.so:math/openblas \
		libopencv_ml.so:graphics/opencv2 \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

USES=		cmake python

USE_GITHUB=	yes
GH_ACCOUNT=	BVLC
GH_TAGNAME=	4ba654f5c88c36ee8ba53964b7faf25c6d7010b4

# FIXME: Add option for atlas instead of openblas
CMAKE_ARGS+=	-DBLAS:STRING="Open"

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

.include <bsd.port.mk>
