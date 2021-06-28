# Created by: Jason Bacon <jwb@FreeBSD.org>

PORTNAME=	port-dev
DISTVERSION=	0.3.0-19
DISTVERSIONSUFFIX=	-g9f8ed56
CATEGORIES=	wip ports-mgmt

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for port development

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	portlint:ports-mgmt/portlint \
		port:ports-mgmt/porttools

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
