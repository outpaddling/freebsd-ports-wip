PORTNAME=	docviewer
DISTVERSION=	0.2.0-2
DISTVERSIONSUFFIX=	-g3bb75e9
CATEGORIES=	wip textproc

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Run the best available PDF viewer
WWW=		https://github.com/outpaddling/docviewer

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/docviewer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docviewer.1 ${STAGEDIR}${PREFIX}/share/man/man1

PLIST_FILES=	bin/docviewer man/man1/docviewer.1.gz

.include <bsd.port.mk>
