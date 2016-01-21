# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	Trimmomatic
PORTVERSION=	0.35
CATEGORIES=	biology java
MASTER_SITES=	http://www.usadellab.org/cms/uploads/supplementary/Trimmomatic/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Flexible read trimming tool for Illumina NGS data

LICENSE=	GPLv3

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Trimmomatic-${PORTVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/trimmomatic-0.35.jar ${STAGEDIR}${JAVAJARDIR}/trimmomatic.jar
	cd ${WRKSRC} && ${COPYTREE_SHARE} adapters ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
