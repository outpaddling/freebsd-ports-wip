PORTNAME=	docviewer
PORTVERSION=	0.2.0
CATEGORIES=	wip textproc

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Run the best available PDF viewer

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/docviewer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docviewer.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/docviewer man/man1/docviewer.1.gz

.include <bsd.port.mk>
