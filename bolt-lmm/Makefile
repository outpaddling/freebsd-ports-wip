# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	bolt-llm
PORTVERSION=	2.3
CATEGORIES=	wip
MASTER_SITES=	https://data.broadinstitute.org/alkesgroup/BOLT-LMM/downloads/
DISTNAME=	BOLT-LMM_v${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Statistics for testing association between phenotype and genotypes

LICENSE=	GPLv3
#LICENSE_FILE=

LIB_DEPENDS+=	libnlopt.so:math/nlopt \
		libopenblas.so:math/openblas \
		liblapack.so:math/lapack \
		libboost_program_options.so:devel/boost-libs

USES+=		compiler:openmp gmake
# Attempts at link errors:
# USES+=	compiler:gcc-c++11-lib
# USE_CXXSTD=	c++11
# https://stackoverflow.com/questions/39591067/undefined-reference-to-boostprogram-options-in-xubuntu
# CXXFLAGS+=	-D_GLIBCXX_USE_CXX11_ABI=0
# Workaround: Build boost-libs with USE_GCC

WRKSRC=		${WRKDIR}/${DISTNAME}/src

ALL_TARGET=	bolt

PLIST_FILES=	bin/bolt

.include <bsd.port.mk>
