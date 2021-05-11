# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	libxtend
DISTVERSION=	0.0.1-32
DISTVERSIONSUFFIX=	-gd5072ae
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include <bsd.port.mk>
