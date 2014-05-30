# New ports collection makefile for:	port-dev
# Date created:		2012-04-16
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	port-dev
PORTVERSION=	0.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for port development

USES+=		tar:xz

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
