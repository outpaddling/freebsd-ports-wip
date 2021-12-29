PORTNAME=	webbrowser
DISTVERSION=	0.3-1
DISTVERSIONSUFFIX=	-g84cb894
CATEGORIES=	wip www

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Wrapper for running the "best" available WEB browser

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/webbrowser man/man1/webbrowser.1.gz

.include <bsd.port.mk>
