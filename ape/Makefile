PORTNAME=	APE
DISTVERSION=	3.5.3-127
DISTVERSIONSUFFIX=	-g53b2d90
CATEGORIES=	wip editors

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Another Programmer's Editor
WWW=		https://acadix.biz/ape.php

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# libtwintk is both a build and run depend.  Ape requires the library and
# headers to build, and libtwintk's terminfo database to run.
BUILD_DEPENDS=	libpare>=1.1.1:wip/libpare \
		twintk>=0.9.4.2:wip/twintk
LIB_DEPENDS=	libxtend.so:wip/libxtend
RUN_DEPENDS=	twintk>=0.9.4.2:wip/twintk \
		webbrowser:wip/webbrowser \
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
