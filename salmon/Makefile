PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		1.6.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# Check cereal version
# staden-io_lib used by Salmon is a fork
# Incompatible with onetbb 2021, so GH_TUPLE onetbb version in CMakeLists.txt
BUILD_DEPENDS=	bash:shells/bash \
		autoconf:devel/autoconf \
		cereal>=1.3.0:devel/cereal \
		libgff==2.0.0:wip/libgff
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake:noninja gmake shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes	# Temporary hack until static tbb libs

GH_ACCOUNT=	COMBINE-lab
GH_TUPLE+=	COMBINE-lab:pufferfish:salmon-v1.6.0:pf/external/pufferfish
GH_TUPLE+=	COMBINE-lab:staden-io_lib:v1.14.8.1:sio/external/staden-io_lib
SHEBANG_FILES=	scripts/*

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/salmon \
		lib/libtbb.so \
		lib/libtbbmalloc.so
CMAKE_ARGS+=	-DHAVE_FAST_MALLOC:BOOL=on \
		-DBOOST_ROOT:PATH=${LOCALBASE} \
		-DFETCHED_PUFFERFISH:BOOL=on \
		-DFETCHED_LIBGFF:BOOL=on \
		-DFETCH_STADEN:BOOL=true

LDFLAGS+=	-lpthread

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/salmon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/external/install/lib/*.so \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
