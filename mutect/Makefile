PORTNAME=	mutect
PORTVERSION=	1.1.6
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Accurate and sensitive cancer mutation detection
WWW=		https://example.com

# Fake to silence warnings.  Configure Broad Institute License
LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/mutect.LICENSE.TXT

# Depend on GATK 2.7.  Will later GATK work as well?
BUILD_DEPENDS+=	scala:lang/scala \
		${LOCALBASE}/share/java/maven31/bin/mvn:devel/maven31
RUN_DEPENDS+=	scala:lang/scala

# Use same Java as gatk
USE_JAVA=	1.8+

USE_GITHUB=	yes
GH_ACCOUNT=	broadinstitute

do-build:
	cd ${WRKSRC} && mvn verify

.include <bsd.port.mk>
