# $FreeBSD$

PORTNAME=	APE
DISTVERSION=	3.5.3-7
DISTVERSIONSUFFIX=	-gc5fe966
CATEGORIES=	wip editors

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Another Programmer's Editor

# Match this to libs
LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# libtwintk is both a build and run depend.  Ape requires the library and
# headers to build, and libtwintk's terminfo database to run.
BUILD_DEPENDS=	${LOCALBASE}/lib/libpare.a:wip/libpare \
		${LOCALBASE}/lib/libbacon.a:wip/libbacon \
		${LOCALBASE}/lib/libtwintk.a:wip/twintk
RUN_DEPENDS=	${LOCALBASE}/share/twintk/terminfo/README:wip/twintk \
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
