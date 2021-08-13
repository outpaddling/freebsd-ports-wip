# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	libxtend
DISTVERSION=	0.1.2-46
DISTVERSIONSUFFIX=	-g54505ab
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	biolibc-0.1.3.[0-3]*

GH_ACCOUNT=	outpaddling

INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include <bsd.port.mk>
