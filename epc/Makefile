PORTNAME=	EPC
DISTVERSION=	0.1.0-2
DISTVERSIONSUFFIX=	-g131e116
CATEGORIES=	wip emulators

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Educational Perrsonal Computer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libtwintk.a:wip/twintk \
		${LOCALBASE}/lib/libbacon.a:wip/libbacon \
		${LOCALBASE}/include/plasm-epc-bits.h:wip/plasm
RUN_DEPENDS=	plasm:wip/plasm

#USES=		localbase
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

pre-build:
	${MAKE} depend

.include <bsd.port.mk>
