# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	htsjdk
PORTVERSION=	1.133
CATEGORIES=	biology
MASTER_SITES=	http://github.com/samtools/htsjdk/archive/
DISTNAME=	${PORTVERSION}
# Same distname as picard-tools
DIST_SUBDIR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	Generic format for storing large nucleotide sequence alignments

# Prefers 1.6, 1.7 should work, but jars built with 1.7 won't run in 1.6 env
USE_JAVA=	1.6+

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

# http://samtools.github.io/htsjdk/building.html#BuildingHtsJdk
do-build:
	cd ${WRKSRC} && ant && ant htsjdk-jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/*.jar \
		${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
