# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: ports/www/runsomebrowser/Makefile,v 1.2 2008/02/07 23:17:13 edwin Exp $

PORTNAME=	webbrowser
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Script for running an available WEB browser

NO_BUILD=	yes
USE_XZ=		yes

MAN1=		webbrowser.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/webbrowser

.include <bsd.port.mk>
