# New ports collection makefile for:	port-dev
# Date created:		2012-04-16
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	port-dev
PORTVERSION=	0.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Tools for port development

RUN_DEPENDS=	portlint:${PORTSDIR}/ports-mgmt/portlint \
		port:${PORTSDIR}/ports-mgmt/porttools

USES+=		tar:xz

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
