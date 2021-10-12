PORTNAME=	libstatgen
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.15
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library for tools from The Center for Statistical Genetics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/general/LICENSE.txt

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	statgen
GH_PROJECT=	libStatGen

PLIST_FILES=	lib/libStatGen.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/libStatGen.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
