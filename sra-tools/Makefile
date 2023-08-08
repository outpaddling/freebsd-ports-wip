PORTNAME=	sra-tools
DISTVERSION=	3.0.6
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives
WWW=		https://github.com/ncbi/sra-tools

LICENSE=		PD LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =

# Use SIMDE for others?
ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Requires a 64-bit processor

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libepoll-shim.so:devel/libepoll-shim \
		libzstd.so:archivers/zstd

USES=		cmake shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/lib64
USE_JAVA=	yes
# Guessing, test on herring
JAVA_VERSION=	17+

SHEBANG_GLOB=	*.sh
GH_ACCOUNT=	ncbi
GH_TUPLE+=	ncbi:ncbi-vdb:${DISTVERSION}:vdb/ncbi-vdb

CMAKE_ARGS+=	-DVDB_LIBDIR:STRING=${WRKSRC}/ncbi-vdb/build/lib

post-extract:
	@${MKDIR} ${WRKSRC}/ncbi-vdb/interfaces/os/freebsd
	@${CP} ${FILESDIR}/*.h ${WRKSRC}/ncbi-vdb/interfaces/os/freebsd
	cd ${WRKDIR} && ${LN} -s ${WRKSRC}/ncbi-vdb .

pre-configure:
	cd ${WRKSRC}/ncbi-vdb/build && cmake .. && make

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*.${DISTVERSION}

.include <bsd.port.mk>
