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
		libopenblas.so:math/openblas

USES=		compiler:openmp gmake

WRKSRC=		${WRKDIR}/${DISTNAME}/src

ALL_TARGET=	bolt

.include <bsd.port.mk>
