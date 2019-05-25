# $FreeBSD$

PORTNAME=	bolt-lmm
DISTVERSION=	2.3.2
CATEGORIES=	wip biology
MASTER_SITES=	https://data.broadinstitute.org/alkesgroup/BOLT-LMM/downloads/
DISTNAME=	BOLT-LMM_v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Statistics for testing association between phenotype and genotypes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libnlopt.so:math/nlopt \
		libopenblas.so:math/openblas \
		libboost_program_options.so:devel/boost-libs

# gcc-c++11-lib needed to link with boost. Also requires openmp, but
# both merely add a GCC requirement.
USES=		compiler:gcc-c++11-lib gmake
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=219484
# Required on 10.3-RELEASE
# USE_CXXSTD=	gnu++11

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/src
CXXFLAGS_i386=	-DUSE_SSE -msse -msse2
CXXFLAGS_amd64=	-DUSE_SSE

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

pre-configure:
	@${RM} ${WRKSRC}/example/*.orig ${WRKSRC}/bolt
	@${REINPLACE_CMD} -e 's|tables/|${DATADIR}/tables/|g' \
		${BUILD_WRKSRC}/BoltParams.cpp
	@${REINPLACE_CMD} -e 's|../tables/|${DATADIR}/tables/|g' \
		${WRKSRC}/example/run_example.sh

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bolt ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} tables ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
