# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	libxtend
DISTVERSION=	0.1.1-4
DISTVERSIONSUFFIX=	-g75f7ac8
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	outpaddling

INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include <bsd.port.mk>
