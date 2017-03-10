# Created by: Jason Bacon <bacon@imacbsd.acadix.biz>
# $FreeBSD$

PORTNAME=	gcta
PORTVERSION=	1.26.0
CATEGORIES=	biology
MASTER_SITES=	http://cnsgenomics.com/software/gcta/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	bacon@imacbsd.acadix.biz
COMMENT=	tool for Genome-wide Complex Trait Analysis

LICENSE=	GPLv3
#LICENSE_FILE=	

USES=		zip

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${UNZIP_CMD} ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
