
PORTNAME=	APE
DISTVERSION=	3.5.3-17
DISTVERSIONSUFFIX=	-g984a05f
CATEGORIES=	wip editors

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Another Programmer's Editor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# libtwintk is both a build and run depend.  Ape requires the library and
# headers to build, and libtwintk's terminfo database to run.
BUILD_DEPENDS=	libpare>=1.1.1:wip/libpare \
		libbacon>=1.2.2.1:wip/libbacon \
		twintk>=0.9.4.2:wip/twintk
RUN_DEPENDS=	twintk>=0.9.4.2:wip/twintk \
		webbrowser:www/webbrowser \
		docviewer:wip/docviewer

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

MAKE_ARGS+=	PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX} \
		DATADIR=${DATADIR} \
		DOCSDIR=${DOCSDIR} \
		STAGEDIR=${STAGEDIR}

pre-build:
	(cd ${WRKSRC} && ${MAKE} depend)

.include <bsd.port.mk>
