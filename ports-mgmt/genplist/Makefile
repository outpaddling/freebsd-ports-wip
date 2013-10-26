# Created by:	Jason Bacon
# $FreeBSD: ports/ports-mgmt/genplist/Makefile,v 1.7 2012/11/17 06:00:45 svnexp Exp $

PORTNAME=	genplist
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Generates a static plist for a port

NO_BUILD=	yes

PLIST_FILES=	bin/genplist

MAN1=		genplist.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/genplist ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/genplist.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
