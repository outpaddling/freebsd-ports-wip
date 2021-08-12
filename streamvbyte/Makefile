PORTNAME=	streamvbyte
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	wip archivers

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Integer compression with SIMD based on Google's varint

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	lemire

CFLAGS+=	-fPIC

PLIST_FILES=	include/streamvbyte.h \
		include/streamvbyte_zigzag.h \
		include/streamvbytedelta.h \
		lib/libstreamvbyte.so \
		lib/libstreamvbyte.so.0.0.1 \
		lib/libstreamvbyte_static.a

# so version taken from basic Makefile
post-stage:
	${RLN}	${STAGEDIR}${PREFIX}/lib/libstreamvbyte.so \
		${STAGEDIR}${PREFIX}/lib/libstreamvbyte.so.0.0.1

do-test:
	cd ${WRKDIR}/.build && ./unit

.include <bsd.port.mk>
