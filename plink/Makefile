# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/biology/plink/Makefile 437439 2017-04-01 15:23:30Z gerald $

PORTNAME=	plink
PORTVERSION=	1.90b4
CATEGORIES=	wip biology science
DISTVERSIONPREFIX=v

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	liblapack.so:math/lapack \
		libcblas.so:math/cblas

# We need Fortran LDFLAGS to link with Lapack.
USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng

WRKSRC=		${WRKDIR}/${PORTNAME}-ng-${PORTVERSION}/1.9

CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include

MAKEFILE=	Makefile.std
ALL_TARGET=	plink

MAKE_FLAGS+=	ZLIB=-lz

#PLIST_FILES=	bin/plink

#do-install:
#	${MKDIR} ${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/plink ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
