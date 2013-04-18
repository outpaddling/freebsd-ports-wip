# New ports collection makefile for:	update-jb-ports
# Date created:		2008-07-19
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	update-jb-ports
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Update ports tree with Jason's development ports

NO_BUILD=	yes

PLIST_FILES=	bin/update-jb-ports bin/remove-jb-ports bin/reinstall-jb-port

MAN1=		update-jb-ports.1 remove-jb-ports.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/update-jb-ports ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/remove-jb-ports ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/reinstall-jb-port ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/update-jb-ports.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/remove-jb-ports.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
