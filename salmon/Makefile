PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		1.10.2
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments
WWW=		https://github.com/COMBINE-lab/salmon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# staden-io_lib used by Salmon is a fork of the traditional dist
# Incompatible with onetbb 2021, so using older devel/tbb for now.
BUILD_DEPENDS=	bash:shells/bash \
		cereal>=1.3.0:devel/cereal \
		libgff==2.0.0:biology/libgff
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libtbb.so:devel/tbb

USES=		cmake:noninja gmake shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	COMBINE-lab
GH_TUPLE+=	COMBINE-lab:pufferfish:salmon-v1.10.2:pf/external/pufferfish
GH_TUPLE+=	jkbonfield:io_lib:io_lib-1-14-15:sio/external/staden-io_lib
SHEBANG_FILES=	scripts/*

PLIST_FILES=	bin/salmon
CMAKE_ARGS+=	-DHAVE_FAST_MALLOC:BOOL=on \
		-DBOOST_ROOT:PATH=${LOCALBASE} \
		-DFETCHED_PUFFERFISH:BOOL=on \
		-DFETCHED_LIBGFF:BOOL=on \
		-DFETCH_STADEN:BOOL=true
WITH_DEBUG=	yes
LDFLAGS+=	-lpthread

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/salmon ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
