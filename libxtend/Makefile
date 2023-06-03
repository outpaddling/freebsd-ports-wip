PORTNAME=	libxtend
DISTVERSION=	0.1.7-20
DISTVERSIONSUFFIX=	-g5413954
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc
WWW=		https://github.com/outpaddling/libxtendc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	outpaddling

INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include <bsd.port.mk>
