PORTNAME=	sra-tools
DISTVERSION=	3.0.6
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives
WWW=		https://github.com/ncbi/sra-tools/wiki

LICENSE=		PD LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =

# Use SIMDE?
ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	NCBI-VDB requires SSE2 instructions, no 32-bit support

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libepoll-shim.so:devel/libepoll-shim \
		libzstd.so:archivers/zstd

USES=		cmake:noninja perl5 shebangfix
USE_PERL5=	build
USE_GITHUB=	yes

SHEBANG_GLOB=	*.sh *.pl
GH_ACCOUNT=	ncbi
GH_TUPLE+=	ncbi:ncbi-vdb:${DISTVERSION}:vdb/ncbi-vdb

FREEBSD_RELEASE=	uname -r | cut -d - -f 1

# for port developers, building with these options may fail
OPTIONS_DEFINE=		DEBUG OPTIMIZED_CFLAGS TEST
DEBUG_PREVENTS=		OPTIMIZED_CFLAGS
DEBUG_CONFIGURE_WITH=	debug
OPTIMIZED_CFLAGS_MAKE_ARGS_OFF=	OPT=""
TEST_TEST_TARGET=	test
TEST_USES=		python

CMAKE_ARGS+=	-DVDB_LIBDIR:STRING=${WRKSRC}/ncbi-vdb/build/lib

MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/ncbi-vdb/interfaces/os/freebsd
	@${CP} ${FILESDIR}/*.h ${WRKSRC}/ncbi-vdb/interfaces/os/freebsd
	cd ${WRKDIR} && ln -s ${WRKSRC}/ncbi-vdb .

pre-configure:
	cd ${WRKSRC}/ncbi-vdb/build && cmake .. && make

.include <bsd.port.mk>
