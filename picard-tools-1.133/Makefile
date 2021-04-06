
PORTNAME=	picard
PORTVERSION=	1.133
CATEGORIES=	wip biology java
MASTER_SITES=	https://github.com/broadinstitute/picard/archive/
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTVERSION}
# Same distname as htsjdk
DIST_SUBDIR=	picard

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line tools for manipulating high-throughput sequencing (HTS) data

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# [1]: http://github.com/samtools/htsjdk
# [2]: http://samtools.sourceforge.net
# [3]: http://vcftools.sourceforge.net/specs.html

BUILD_DEPENDS=	ant:devel/apache-ant \
		git:devel/git \
		${JAVAJARDIR}/htsjdk/htsjdk-${PORTVERSION}.jar:wip/htsjdk

RUN_DEPENDS=	samtools01==0.1.19:wip/samtools0119

# Prefers 1.6, 1.7 should work, but jars built with 1.7 won't run in 1.6 env
USE_JAVA=	1.6+
JAVA_RUN=	yes

MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

do-build:
	cd ${WRKSRC} && tar zxvf ${DISTDIR}/htsjdk/${PORTVERSION}.tar.gz
	cd ${WRKSRC} && ${MV} htsjdk-${PORTVERSION} htsjdk
	cd ${WRKSRC} && ant -lib lib/ant package-commands

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}

.include <bsd.port.mk>
