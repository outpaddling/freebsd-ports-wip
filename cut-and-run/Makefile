PORTNAME=	cut-and-run
DISTVERSION=	0.0.1
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a text file into segments and process in parallel

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

PLIST_FILES=	bin/cut-and-run

pre-build:
	cd ${WRKSRC} && make depend

.include <bsd.port.mk>
