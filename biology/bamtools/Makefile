# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bamtools
PORTVERSION=	2.4.0
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	API and toolkit for handling BAM files

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	pezmaster31
GH_TAGNAME=	v${PORTVERSION}

.include <bsd.port.pre.mk>

# Just for speed: Recent GCC has better optimizer
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

do-build:
	${MKDIR} ${WRKSRC}/build && cd ${WRKSRC}/build && cmake .. && ${MAKE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	${MKDIR} ${STAGEDIR}${PREFIX}/include/api
	${MKDIR} ${STAGEDIR}${PREFIX}/include/api/algorithms
	${MKDIR} ${STAGEDIR}${PREFIX}/include/shared
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bamtools-2.4.0 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib/*.so* ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDOR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/api/*.h ${STAGEDIR}${PREFIX}/include/api/
	${INSTALL_DATA} ${WRKSRC}/include/api/algorithms/Sort.h ${STAGEDIR}${PREFIX}/include/api/algorithms/
	${INSTALL_DATA} ${WRKSRC}/include/shared/bamtools_global.h ${STAGEDIR}${PREFIX}/include/shared/
.include <bsd.port.post.mk>
