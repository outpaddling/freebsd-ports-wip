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
		libboost_program_options.so:devel/boost-libs

# USES=		gmake
USES=		compiler:openmp gmake

# https://stackoverflow.com/questions/39591067/undefined-reference-to-boostprogram-options-in-xubuntu
# Didn't help
# CXXFLAGS+=	-D_GLIBCXX_USE_CXX11_ABI=0

WRKSRC=		${WRKDIR}/${DISTNAME}/src

ALL_TARGET=	bolt

.include <bsd.port.mk>
