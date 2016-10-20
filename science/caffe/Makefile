# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	caffe
PORTVERSION=	2016.10.20
CATEGORIES=	science

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	Fast open framework for deep learning

# boost, glog, gflags, protobuf, hdf5, opencv, atlas
LIB_DEPENDS+=	liblmdb.so:databases/lmdb \
		libleveldb.so:databases/leveldb

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	BVLC
GH_TAGNAME=	4ba654f5c88c36ee8ba53964b7faf25c6d7010b4

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

.include <bsd.port.mk>
