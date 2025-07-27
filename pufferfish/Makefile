PORTNAME=		pufferfish
DISTVERSIONPREFIX=	salmon-v
DISTVERSION=		1.10.3
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	An efficient index for the colored, compacted, de Bruijn graph
WWW=		https://github.com/COMBINE-lab/pufferfish

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# devel/tbb is obsolete, but salmon is not compatible with onetbb 2021.3
LIB_DEPENDS=	libtbb.so:devel/tbb

# pkgconfig used by cmake find jemalloc
USES=		cmake:noninja gmake localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	COMBINE-lab

# no libtbbmalloc_proxy.so in devel/tbb
CMAKE_ARGS+=	-DTBB_tbb_LIBRARY:PATH=${LOCALBASE}/lib/libtbb.so \
                -DTBB_tbbmalloc_LIBRARY:PATH=${LOCALBASE}/lib/libtbbmalloc.so
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
