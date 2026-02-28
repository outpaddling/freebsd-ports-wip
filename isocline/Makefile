PORTNAME=		isocline
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.9
CATEGORIES=		wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pure C library alternative to the GNU readline library
WWW=		https://example.com/isocline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja
USE_GITHUB=	yes
GH_ACCOUNT=	daanx

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${BUILD_WRKSRC}/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
