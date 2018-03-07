# $FreeBSD$

PORTNAME=	bamtools
PORTVERSION=	2.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	API and toolkit for handling BAM files

LICENSE=	MIT

USES=		cmake:outsource

USE_LDCONFIG=	yes

LIB_DEPENDS+=	libjsoncpp.so:devel/jsoncpp

USE_GITHUB=	yes
GH_ACCOUNT=	pezmaster31

CMAKE_ON+=	BUILD_SHARED_LIBS
CMAKE_ARGS+=	-DLIB_DIR=${PREFIX}/lib

.include <bsd.port.pre.mk>

# Just for speed: Recent compilers have better optimizers
USES=		compiler:c++11-lang

.include <bsd.port.post.mk>
