# $FreeBSD$

PORTNAME=	bamtools
PORTVERSION=	2.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	API and toolkit for handling BAM files

LICENSE=	MIT

LIB_DEPENDS+=	libjsoncpp.so:devel/jsoncpp

USES=		cmake:outsource compiler:c++11-lang
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pezmaster31

CMAKE_ON+=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
