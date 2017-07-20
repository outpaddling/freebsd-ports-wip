# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	canu
PORTVERSION=	1.5
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology
PKGNAMESUFFIX=	-devel

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Single molecule sequence assembler for genomes large and small

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../README.license.GPL

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		compiler:openmp gmake perl5

USE_GITHUB=	yes
GH_ACCOUNT=	marbl

# May work on other 64-bit processors, but untested
ONLY_FOR_ARCHS=	amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

# Screwy Makefile compiles directly into ${DESTDIR}${PREFIX}
MAKE_ENV+=	DESTDIR=${WRKSRC}

post-patch:
	${REINPLACE_CMD} \
		-e 's|-O4|-O2|g' \
		-e 's|-funroll-loops||g' \
		-e 's|-fexpensive-optimizations||g' \
		${WRKSRC}/Makefile

# FIXME: Unravel the willy-nilly directory structure.
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/canu-1.5
	${CP} -R ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin \
		${STAGEDIR}${PREFIX}/canu-1.5

.include <bsd.port.mk>
