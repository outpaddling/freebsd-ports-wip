PORTNAME=	cut-and-run
DISTVERSION=	0.0.1-1
DISTVERSIONSUFFIX=	-g85c313a
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Split a text file into segments and process in parallel
WWW=		https://github.com/outpaddling/cut-and-run

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

PLIST_FILES=	bin/cut-and-run man/man1/cut-and-run.1.gz

pre-build:
	cd ${WRKSRC} && make depend

.include <bsd.port.mk>
