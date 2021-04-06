
PORTNAME=	sra-tools
DISTVERSION=	2.8.2-3
CATEGORIES=	wip biology

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives

LICENSE=	PD LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =
# The executables contain functions from biology/ncbi-vdb port,
# which is derived from a part of LGPL-licensed GNU C Library or Judy library.

BUILD_DEPENDS=	bash:shells/bash \
		${NONEXISTENT}:wip/ncbi-vdb:build \
		${LOCALBASE}/lib/libngs-c++.a:wip/ngs-sdk
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libmbedtls.so:security/mbedtls

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

USES=		compiler gmake perl5 shebangfix
USE_PERL5=	build
SHEBANG_GLOB=	*.sh *.pl

GNU_CONFIGURE=	yes
VDBSRC_CMD=	${MAKE} -C ${.CURDIR}/../ncbi-vdb -V WRKSRC
CONFIGURE_ARGS=	--with-ngs-sdk-prefix=${LOCALBASE} \
		--with-ncbi-vdb-sources=$$(${VDBSRC_CMD}) \
		--with-ncbi-vdb-build=$$(${VDBSRC_CMD})/${CONFIGURE_TARGET}/ncbi-vdb/ \
		--with-xml2-prefix=${LOCALBASE} \
		--with-hdf5-prefix=${LOCALBASE} \
		--with-mbedtls-prefix=${LOCALBASE} \
		CC="${CC}" CXX="${CXX}" TOOLS="${CHOSEN_COMPILER_TYPE}"
MAKE_ARGS=	CCNAME=${CC} CXXNAME=${CXX} PKGCFLAGS="${CFLAGS}" \
		INST_ETCDIR=${STAGEDIR}${PREFIX}/etc
#MAKE_JOBS_NUMBER_LIMIT=	4
MAKE_JOBS_UNSAFE=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	NCBI-VDB requires SSE2 instructions
BROKEN_i386=	buggy output

# for port developpers, building with these options may fail
OPTIONS_DEFINE=	DEBUG GCC OPTIMIZED_CFLAGS TEST
DEBUG_PREVENTS=	OPTIMIZED_CFLAGS
DEBUG_CONFIGURE_WITH=	debug
GCC_USE=	gcc=yes
OPTIMIZED_CFLAGS_MAKE_ARGS_OFF=	OPT=""
TEST_TEST_TARGET=	test
TEST_USES=	python

pre-patch:
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/build/
	@for f in ${WRKSRC}/build/ld.linux.*.sh; do ${CP} -p $${f} $${f%linux*}bsd$${f#*linux}; done
	@${CP} -p ${WRKSRC}/build/ld.linux.gcc.sh ${WRKSRC}/build/ld.bsd.clang.sh

post-patch-TEST-on:
	${REINPLACE_CMD} -e 's#python#${PYTHON_CMD}#' ${WRKSRC}/test/kget/Makefile

post-configure:
	@${ECHO} ${CHOSEN_COMPILER_TYPE} > ${WRKSRC}/build/COMP

post-build-TEST-on:	do-test

.include <bsd.port.mk>
