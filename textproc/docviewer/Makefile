# New ports collection makefile for:	docviewer
# Date created:		2010-11-15
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	docviewer
PORTVERSION=	0.1
CATEGORIES=	textproc
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Run the best available PDF viewer

NO_BUILD=	yes

MAN1=		docviewer.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/docviewer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docviewer.1 ${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/docviewer

.include <bsd.port.mk>
