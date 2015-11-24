# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	Trimmomatic
PORTVERSION=	0.35
CATEGORIES=	biology java
MASTER_SITES=	http://www.usadellab.org/cms/uploads/supplementary/Trimmomatic/
DISTNAME=	${PORTNAME}-Src-${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Flexible read trimming tool for Illumina NGS data

LICENSE=	GNUv3

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

# Prefers 1.6, 1.7 should work, but jars built with 1.7 won't run in 1.6 env
USES=		zip
USE_JAVA=	1.6+
JAVA_RUN=	yes

WRKSRC=		${WRKDIR}/trimmomatic-{$PORTVERSION}

MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

do-build:
	cd ${WRKSRC} && ant # -lib lib/ant package-commands

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}

.include <bsd.port.mk>
