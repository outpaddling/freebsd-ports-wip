# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	canu
PORTVERSION=	1.5
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology java

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Single molecule sequence assembler for genomes large and small

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../README.license.GPL

LIB_DEPENDS+=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS+=	gnuplot:math/gnuplot

USES=		compiler:openmp gmake perl5
USE_JAVA=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.8+

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
		-e 's|amd64|${ARCH}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|\\$$bin/mhap-|${JAVAJARDIR}/mhap-|g' \
		${WRKSRC}/pipelines/canu/OverlapMhap.pm
	${REINPLACE_CMD} -e 's|RealBin/lib|RealBin/../${SITE_PERL_REL}/canu|g' \
		${WRKSRC}/pipelines/canu.pl

post-build:
	${MKDIR} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${SITE_PERL_REL}
	${MV} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/lib/canu \
		${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${SITE_PERL_REL}
	${RMDIR} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/lib
	${MV} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/*.a \
		${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib
	${MKDIR} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${JAVAJARDIR:S,^${PREFIX}/,,}
	${MV} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/*.jar \
		${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${JAVAJARDIR:S,^${PREFIX}/,,}

# FIXME: Unravel the willy-nilly directory structure.
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}
	cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && ${COPYTREE_BIN} bin \
		${STAGEDIR}${PREFIX}
	cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && ${COPYTREE_SHARE} "lib share" \
		${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
