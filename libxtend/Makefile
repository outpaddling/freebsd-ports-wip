# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	libxtend
DISTVERSION=	0.1.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	outpaddling

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxtend.so.1.0

.include <bsd.port.mk>
