# New ports collection makefile for:	docviewer
# Date created:		2010-11-15
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	docviewer
PORTVERSION=	0.2
CATEGORIES=	textproc
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Run the best available PDF viewer

NO_BUILD=	yes
USES=		tar:xz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/docviewer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docviewer.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/docviewer man/man1/docviewer.1.gz

.include <bsd.port.mk>
