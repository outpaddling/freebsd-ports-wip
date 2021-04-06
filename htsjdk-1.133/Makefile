
PORTNAME=	htsjdk
PORTVERSION=	1.133
CATEGORIES=	wip biology
MASTER_SITES=	http://github.com/samtools/htsjdk/archive/
DISTNAME=	${PORTVERSION}
# Same distname as picard-tools
DIST_SUBDIR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generic format for storing large nucleotide sequence alignments

# Prefers 1.6, 1.7 should work, but jars built with 1.7 won't run in 1.6 env
USE_JAVA=	1.6+

BUILD_DEPENDS=	ant:devel/apache-ant

MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

# http://samtools.github.io/htsjdk/building.html#BuildingHtsJdk
do-build:
	cd ${WRKSRC} && ant && ant htsjdk-jar

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}

.include <bsd.port.mk>
