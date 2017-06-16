# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	canu
PORTVERSION=	1.4
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	A single molecule sequence assembler for genomes large and small

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../README.license.GPL

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		compiler:openmp gmake perl5

USE_GITHUB=	yes
GH_ACCOUNT=	marbl

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
	${MKDIR} ${STAGEDIR}${PREFIX}/canu
	${CP} -R ${WRKSRC}/usr/local/FreeBSD-${ARCH}/bin \
		${STAGEDIR}${PREFIX}/canu

.include <bsd.port.mk>
