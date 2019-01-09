# $FreeBSD$

PORTNAME=	gcta
PORTVERSION=	1.26.0
CATEGORIES=	wip biology
MASTER_SITES=	http://cnsgenomics.com/software/gcta/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Complex Trait Analysis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GNU_General_Public_License_v3.txt

BUILD_DEPENDS=	eigen>=3:math/eigen3 \
		lapack++>0:math/lapack++ \
		cblas>0:math/cblas \
		lapacke>0:math/lapacke
LIB_DEPENDS+=	libopenblas.so:math/openblas

USES=		compiler:openmp dos2unix gmake zip

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3 -fopenmp

# -I${LOCALBASE}/include/lapackpp

do-extract:
	@${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${UNZIP_CMD} ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
