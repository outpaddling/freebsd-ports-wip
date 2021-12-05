PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		1.6.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# Check cereal version
BUILD_DEPENDS=	bash:shells/bash \
		autoconf:devel/autoconf \
		cereal>=1.3.0:devel/cereal \
		libgff==2.0.0:wip/libgff
LIB_DEPENDS=	libtbb.so:devel/onetbb \
		libboost_system.so:devel/boost-libs \
		libstadenio.so:wip/staden-io

USES=		cmake shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	COMBINE-lab
GH_TUPLE+=      COMBINE-lab:pufferfish:salmon-v1.6.0:pf/external/pufferfish
GH_TUPLE+=      COMBINE-lab:staden-io:v1.14.8.1:pf/external/staden-io_lib
# GH_TUPLE+=      COMBINE-lab:libgff:v2.0.0:gff/external/libgff-2.0.0
SHEBANG_FILES=	scripts/*

# https://salmon.readthedocs.io/en/latest/building.html
#LIBS+=		-L${LOCALBASE}/lib -lthr
PLIST_FILES=	bin/salmon lib/libsalmon_core.a
#CONFIGURE_ENV=	DISTDIR=${DISTDIR} DIST_SUBDIR=${DIST_SUBDIR}
#CMAKE_ARGS+=	-DDISTDIR:PATH=${DISTDIR} -DDIST_SUBDIR:PATH=${DIST_SUBDIR}
# FreeBSD's base malloc is jemalloc
# -DTBB_INSTALL_DIR:PATH=${LOCALBASE} does not work
CMAKE_ARGS+=	-DHAVE_FAST_MALLOC:BOOL=on \
		-DBOOST_ROOT:PATH=${LOCALBASE} \
		-DFETCHED_PUFFERFISH:BOOL=on \
		-DFETCHED_LIBGFF:BOOL=on \
		-DTBB_tbb_LIBRARY:PATH=${LOCALBASE}/lib/libtbb.so \
		-DTBB_tbbmalloc_LIBRARY:PATH=${LOCALBASE}/lib/libtbbmalloc.so \
		-DTBB_tbbmalloc_proxy_LIBRARY:PATH=${LOCALBASE}/lib/libtbbmalloc_proxy.so

.include <bsd.port.mk>
