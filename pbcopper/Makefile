# $FreeBSD$

PORTNAME=	pbcopper
DISTVERSION=	5.0.1p20180316
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Core C++ library for data structures, algorithms, and utilities

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake:outsource compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	89304a3323bf920796edae1aadff5e2181dd5b1c

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
