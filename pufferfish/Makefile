PORTNAME=		pufferfish
DISTVERSIONPREFIX=	salmon-v
DISTVERSION=		1.5.2
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	An efficient index for the colored, compacted, de Bruijn graph

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/onetbb

# pkgconfig used by cmake find jemalloc
USES=		cmake:noninja gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	COMBINE-lab

CMAKE_ARGS+=	-DJEMALLOC_LIBRARY:STRING="/lib/libc.so" \
                -DTBB_tbb_LIBRARY:PATH=${LOCALBASE}/lib/libtbb.so \
                -DTBB_tbbmalloc_LIBRARY:PATH=${LOCALBASE}/lib/libtbbmalloc.so \
                -DTBB_tbbmalloc_proxy_LIBRARY:PATH=${LOCALBASE}/lib/libtbbmalloc

.include <bsd.port.mk>
