# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# Tables are huge and may not be necessary for bolt to function.
# Maybe omit them from plist and add a message about where to get them?
# Why isn't makeplist using EXAMPLESDIR and DATADIR?

PORTNAME=	bolt-lmm
PORTVERSION=	2.3
CATEGORIES=	wip
MASTER_SITES=	https://data.broadinstitute.org/alkesgroup/BOLT-LMM/downloads/
DISTNAME=	BOLT-LMM_v${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Statistics for testing association between phenotype and genotypes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS+=	libnlopt.so:math/nlopt \
		libopenblas.so:math/openblas \
		liblapack.so:math/lapack \
		libboost_program_options.so:devel/boost-libs

# gcc-c++11-lib needed to link with boost. Also requires compiler:openmp, but
# gcc-c++11-lib is sufficient as it merely adds a GCC requirement.
USES=		compiler:gcc-c++11-lib gmake
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=219484
# Required on 10.3-RELEASE
USE_CXXSTD=	gnu++11

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/src

post-patch:
	${RM} ${WRKSRC}/example/*.orig

post-install:
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} tables ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
