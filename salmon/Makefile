PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		1.6.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# staden-io_lib used by Salmon is a fork
# Incompatible with onetbb 2021, so using older devel/tbb for now.
# Appears that TBB will only build shared libs, so GH_TUPLE will only add
# another conflict.  Maybe hack TBB Makefile to change names to libsalmontbb*?
BUILD_DEPENDS=	bash:shells/bash \
		cereal>=1.3.0:devel/cereal \
		libgff==2.0.0:wip/libgff
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libtbb.so:devel/tbb

USES=		cmake:noninja gmake shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	COMBINE-lab
GH_TUPLE+=	COMBINE-lab:pufferfish:salmon-v1.6.0:pf/external/pufferfish
GH_TUPLE+=	COMBINE-lab:staden-io_lib:v1.14.8.1:sio/external/staden-io_lib
SHEBANG_FILES=	scripts/*

PLIST_FILES=	bin/salmon
CMAKE_ARGS+=	-DHAVE_FAST_MALLOC:BOOL=on \
		-DBOOST_ROOT:PATH=${LOCALBASE} \
		-DFETCHED_PUFFERFISH:BOOL=on \
		-DFETCHED_LIBGFF:BOOL=on \
		-DFETCH_STADEN:BOOL=true

LDFLAGS+=	-lpthread

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/salmon ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
