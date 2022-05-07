# Created by: Jason Bacon <jwb@FreeBSD.org>

PORTNAME=	port-dev
DISTVERSION=	0.3.0-30
DISTVERSIONSUFFIX=	-ge444b2a
CATEGORIES=	wip ports-mgmt

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for port development

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	portlint:ports-mgmt/portlint

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
