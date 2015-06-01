# Created by: Jason Wayne Bacon <bacon@sciprog.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	picard
PORTVERSION=	1.131
CATEGORIES=	biology
MASTER_SITES=	https://github.com/broadinstitute/picard/archive/
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTVERSION}

MAINTAINER=	bacon@sciprog.ceas.uwm.edu
COMMENT=

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# [1]: http://github.com/samtools/htsjdk
# [2]: http://samtools.sourceforge.net
# [3]: http://vcftools.sourceforge.net/specs.html

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

# Prefers 1.6, 1.7 should work, but jars built with 1.7 won't run in 1.6 env
USE_JAVA=	1.6+
JAVA_RUN=	yes

MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

do-build:
	cd ${WRKSRC} && ant -lib lib/ant package-commands

.include <bsd.port.mk>
