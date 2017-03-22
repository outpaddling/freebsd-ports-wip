# Created by: Jason W. Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	port-dev
PORTVERSION=	0.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Tools for port development

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	portlint:ports-mgmt/portlint \
		port:ports-mgmt/porttools

USES+=		tar:xz

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
