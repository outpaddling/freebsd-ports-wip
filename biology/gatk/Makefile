# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	GenomeAnalysisTK
PORTVERSION=	3.4
CATEGORIES=	biology science
DISTNAME=	${PORTNAME}-${PORTVERSION}-0

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Analyse next-generation resequencing data

USES=		tar:bzip2
USE_JAVA=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	broadgsa
GH_PROJECT=	gatk-protected

RUN_DEPENDS+=	R:math/R

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/*.jar ${STAGEDIR}${PREFIX}/bin
	cd ${WRKDIR}/resources && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
