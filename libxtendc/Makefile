# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	libxtendc
DISTVERSION=	0.0.1-1
DISTVERSIONSUFFIX=	-g29f81c4
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

PLIST_FILES=	lib/libxtendc.a include/xtendc.h include/xtendc-protos.h

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include <bsd.port.mk>
