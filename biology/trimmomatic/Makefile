# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	Trimmomatic
PORTVERSION=	0.35
CATEGORIES=	biology java
MASTER_SITES=	http://www.usadellab.org/cms/uploads/supplementary/Trimmomatic/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Flexible read trimming tool for Illumina NGS data

LICENSE=	GPLv3

# Prefers 1.6, 1.7 should work, but jars built with 1.7 won't run in 1.6 env
USES=		zip
USE_JAVA=	1.6+
JAVA_RUN=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Trimmomatic-${PORTVERSION}

MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/trimmomatic-0.35.jar ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC}/adapters && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
