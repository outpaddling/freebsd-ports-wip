# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	filevercmp
PORTVERSION=	68966fcee774f7b7133dcfdd9a9d4ce16ef86143
CATEGORIES=	sysutils

MAINTAINER=	jwbacon@tds.net
COMMENT=	filevercmp function as in sort --version-sort

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

PLIST_FILES=	bin/filevercmp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filevercmp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
