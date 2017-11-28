# New ports collection makefile for:	ssh-authorize
# Date created:		2009-04-13
# Whom:			Jason Bacon <jwb@FreeBSD.org>
#
# $FreeBSD: ports/ports-mgmt/genplist/Makefile,v 1.1 2007/04/20 12:40:28 miwi Exp $
#

PORTNAME=	ssh-authorize
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Set up ssh keys on a remote host

NO_BUILD=	yes

PLIST_FILES=	bin/ssh-authorize

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ssh-authorize ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
