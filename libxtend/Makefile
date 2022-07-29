PORTNAME=	libxtend
DISTVERSION=	0.1.6-5
DISTVERSIONSUFFIX=	-gf4c3bbd
CATEGORIES=	wip devel

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
