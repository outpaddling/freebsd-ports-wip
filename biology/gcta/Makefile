# Created by: Jason Bacon <bacon@imacbsd.acadix.biz>
# $FreeBSD$

PORTNAME=	gcta
PORTVERSION=	1.26.0
CATEGORIES=	biology
MASTER_SITES=	http://cnsgenomics.com/software/gcta/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	bacon4000@gmail.com
COMMENT=	tool for Genome-wide Complex Trait Analysis

LICENSE=	GPLv3
#LICENSE_FILE=	

BUILD_DEPENDS=	eigen>=3:math/eigen3
LIB_DEPENDS+=	libopenblas.so:math/openblas

USES=		compiler:openmp gmake zip

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${UNZIP_CMD} ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
