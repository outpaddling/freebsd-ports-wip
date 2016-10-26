# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# Requires login to download the jar file

PORTNAME=	GenomeAnalysisTK
PORTVERSION=	3.6
CATEGORIES=	biology science
DISTNAME=	${PORTNAME}-${PORTVERSION}-0

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Analyse next-generation resequencing data

# Not really.  Set up special license case here.
LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
USE_JAVA=	1.8+

USE_GITHUB=	yes
GH_ACCOUNT=	broadgsa
GH_PROJECT=	gatk-protected

RUN_DEPENDS+=	R:math/R

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}
	cd ${WRKDIR}/resources && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
