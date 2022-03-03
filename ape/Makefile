# Created by: Jason Bacon <jwb@FreeBSD.org>

PORTNAME=	APE
DISTVERSION=	3.5.3-102
DISTVERSIONSUFFIX=	-ga4f47c5
CATEGORIES=	wip editors

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Another Programmer's Editor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# libtwintk is both a build and run depend.  Ape requires the library and
# headers to build, and libtwintk's terminfo database to run.
BUILD_DEPENDS=	libpare>=1.1.1:wip/libpare \
		twintk>=0.9.4.2:wip/twintk
LIB_DEPENDS=	libxtend.so:wip/libxtend
RUN_DEPENDS=	twintk>=0.9.4.2:wip/twintk \
		webbrowser:www/webbrowser \
		docviewer:wip/docviewer

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

MAKE_ARGS+=	PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX} \
		DATADIR=${DATADIR} \
		DOCSDIR=${DOCSDIR} \
		STAGEDIR=${STAGEDIR} \
		VERSION=${PORTVERSION}

pre-build:
	(cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE})

.include <bsd.port.mk>
