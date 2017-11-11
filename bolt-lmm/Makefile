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

# gcc-c++11-lib needed to link with boost. Also requires compiler:openmp, but
# gcc-c++11-lib is sufficient as it merely adds a GCC requirement.
USES=		compiler:gcc-c++11-lib gmake

WRKSRC=		${WRKDIR}/${DISTNAME}/src

ALL_TARGET=	bolt

PLIST_FILES=	bin/bolt

.include <bsd.port.mk>
