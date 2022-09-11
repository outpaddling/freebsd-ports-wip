PORTNAME=		gephi
DISTVERSION=		0.9.2
CATEGORIES=		wip graphics

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	visualization and exploration software for graphs and networks
WWW=		https://gephi.org/

# Also CDDL 1.0
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	mvn:devel/maven

USE_JAVA=	yes
USE_GITHUB=	yes

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn --offline \
		-fae install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR}

.include <bsd.port.mk>
