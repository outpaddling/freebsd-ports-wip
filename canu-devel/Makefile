# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	canu
PORTVERSION=	2017.10.16
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Single molecule sequence assembler for genomes large and small

LICENSE=	GPLv2
# LICENSE_FILE=	${WRKSRC}/../README.license.GPL

LIB_DEPENDS+=	libboost_regex.so:devel/boost-libs
# RUN_DEPENDS+=	gnuplot:math/gnuplot

USES=		compiler:openmp gmake perl5
USE_JAVA=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.8+

USE_GITHUB=	yes
GH_ACCOUNT=	marbl
GH_TAGNAME=	e2196699031b7f1e4257a78600eca3988c6a9a45

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}/src

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

# Upstream does not want to use lib/perl5/site_perl
post-build:
	${MKDIR} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/perl5
	${MV} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/site_perl \
		${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/perl5

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}
	cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && ${COPYTREE_BIN} bin \
		${STAGEDIR}${PREFIX}
	cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && ${COPYTREE_SHARE} "lib share" \
		${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
