# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docviewer
PORTVERSION=	0.2
CATEGORIES=	wip textproc
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Run the best available PDF viewer

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
USES=		tar:xz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/docviewer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docviewer.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/docviewer man/man1/docviewer.1.gz

.include <bsd.port.mk>
