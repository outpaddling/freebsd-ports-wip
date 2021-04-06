
PORTNAME=		pufferfish
DISTVERSIONPREFIX=	salmon-v
DISTVERSION=		1.1.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	An efficient index for the colored, compacted, de Bruijn graph

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/tbb

# pkgconfig used by cmake find jemalloc
USES=		cmake:noninja gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	COMBINE-lab

CMAKE_ARGS+=	-DJEMALLOC_LIBRARY:STRING="/lib/libc.so"

.include <bsd.port.mk>
