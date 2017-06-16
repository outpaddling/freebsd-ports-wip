# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	pbcopper
PORTVERSION=	2016.09.13
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Core C++ library for data structures, algorithms, and utilities

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake:outsource compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	ce9a4b6

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
