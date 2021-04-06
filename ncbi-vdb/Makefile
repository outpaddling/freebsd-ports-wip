
PORTNAME=	ncbi-vdb
DISTVERSION=	2.8.2-2
CATEGORIES=	wip biology

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	NCBI's virtualized back-end for accessing Sequence Read Archive

LICENSE=	PD LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =	${DISTNAME}${EXTRACT_SUFX}
# This port never use the bundled libraries otherwise licensed.

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libmbedtls.so:security/mbedtls

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi
GH_TUPLE+=	ncbi:ngs:1.3.0:ngs

USES=		compiler gmake perl5 shebangfix
USE_PERL5=	build
SHEBANG_GLOB=	*.sh *.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-prefix=${LOCALBASE} \
		--with-hdf5-prefix=${LOCALBASE} \
		--with-mbedtls-prefix=${LOCALBASE} \
		CC="${CC}" CXX="${CXX}" TOOLS="${CHOSEN_COMPILER_TYPE}"
MAKE_ARGS+=	CCNAME=${CC} CXXNAME=${CXX} PKGCFLAGS="${CFLAGS}"
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	libs/search/nucstrstr.c requires SSE2 instructions

# for port developpers, building with these options may fail
OPTIONS_DEFINE=	DEBUG GCC OPTIMIZED_CFLAGS TEST
DEBUG_PREVENTS=	OPTIMIZED_CFLAGS
DEBUG_CONFIGURE_WITH=	debug
GCC_USE=	gcc=yes
OPTIMIZED_CFLAGS_MAKE_ARGS_OFF=	OPT=""
TEST_TEST_TARGET=	test

post-extract:
	@${LN} -sf ${WRKSRC_ngs} ${WRKDIR}/ngs
	@${LN} -sf ${WRKSRC} ${WRKDIR}/${PORTNAME}

pre-patch:
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/build/
	@for f in ${WRKSRC}/build/ld.linux.*.sh; do ${CP} -p $${f} $${f%linux*}bsd$${f#*linux}; done
	@${CP} -p ${WRKSRC}/build/ld.linux.gcc.sh ${WRKSRC}/build/ld.bsd.clang.sh
	@${MKDIR} ${WRKSRC}/interfaces/os/bsd
	@${CP} -p ${WRKSRC}/interfaces/os/mac/endian.h ${WRKSRC}/interfaces/os/bsd/
	@${REINPLACE_CMD} -e 's/vdb_mbedtls_/mbedtls_/g' ${WRKSRC}/libs/kns/tls.c
	@${RM} -rf ${WRKSRC}/interfaces/ext/mbedtls

post-patch:
	@${GREP} -q '@@PREFIX@@' ${WRKSRC}/libs/kfg/config.c || (echo "@@PREFIX@@ in file/patch-libs_kfg_config.c is overwritten probably due to using 'make makepatch'"; exit 1)
	@${REINPLACE_CMD} -e 's#@@PREFIX@@#"${PREFIX}"#' ${WRKSRC}/libs/kfg/config.c

post-configure:
	@${ECHO} ${CHOSEN_COMPILER_TYPE} > ${WRKSRC}/build/COMP

post-build-TEST-on:	do-test

.include <bsd.port.mk>
