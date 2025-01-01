PORTNAME=	port-dev
DISTVERSION=	0.3.0-51
DISTVERSIONSUFFIX=	-gc32c2ff
CATEGORIES=	wip ports-mgmt

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for port development
WWW=		https://github.com/outpaddling/port-dev

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	portlint:ports-mgmt/portlint

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/port-poudriere-test \
		${STAGEDIR}${PREFIX}/sbin/port-poudriere-pkg

.include <bsd.port.mk>
