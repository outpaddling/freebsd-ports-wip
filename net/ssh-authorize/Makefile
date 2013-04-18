# New ports collection makefile for:	ssh-authorize
# Date created:		2009-04-13
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD: ports/ports-mgmt/genplist/Makefile,v 1.1 2007/04/20 12:40:28 miwi Exp $
#

PORTNAME=	ssh-authorize
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Set up ssh keys on a remote host

NO_BUILD=	yes

PLIST_FILES=	bin/ssh-authorize

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ssh-authorize ${PREFIX}/bin

.include <bsd.port.mk>
