PORTNAME=	port-dev
DISTVERSION=	0.3.0-63
DISTVERSIONSUFFIX=	-g2df7dd7
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
	${INSTALL_MAN} ${WRKSRC}/Man/* ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
