# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$
# Test new versions with Trinity before upgrading

PORTNAME=	trimmomatic
PORTVERSION=	0.36
CATEGORIES=	wip biology java
MASTER_SITES=	http://www.usadellab.org/cms/uploads/supplementary/Trimmomatic/
DISTNAME=	Trimmomatic-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Flexible read trimming tool for Illumina NGS data

LICENSE=	GPLv3

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/Trimmomatic-${PORTVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/trimmomatic-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/trimmomatic.jar
	cd ${WRKSRC} && ${COPYTREE_SHARE} adapters ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
