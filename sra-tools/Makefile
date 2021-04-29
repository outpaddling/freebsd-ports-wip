# $FreeBSD$

PORTNAME=	sra-tools
DISTVERSION=	2.11.0
CATEGORIES=	wip biology

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives

LICENSE=	PD LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/libngs-c++.a:biology/ngs-sdk \
		${NONEXISTENT}:biology/ncbi-vdb:build
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libmbedtls.so:security/mbedtls \
		libepoll-shim.so:devel/libepoll-shim

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

USES=		gmake perl5 shebangfix
USE_PERL5=	build
SHEBANG_GLOB=	*.sh *.pl

GNU_CONFIGURE=	yes

NCBI_VDB_WRKSRC=	$$(make -C ${PORTSDIR}/biology/ncbi-vdb -V WRKSRC)
NCBI_VDB_FILESDIR=	$$(make -C ${PORTSDIR}/biology/ncbi-vdb -V FILESDIR)

CONFIGURE_ARGS=	--with-ngs-sdk-prefix=${LOCALBASE} \
		--with-ncbi-vdb-sources=${NCBI_VDB_WRKSRC} \
		--with-xml2-prefix=${LOCALBASE} \
		--with-hdf5-prefix=${LOCALBASE} \
		CC="${CC}" CXX="${CXX}" TOOLS="${CHOSEN_COMPILER_TYPE}" \
		--with-ncbi-vdb-build=${NCBI_VDB_WRKSRC}/amd64-portbld-freebsd12.2
#		-d
#		--with-mbedtls-prefix=${LOCALBASE}
MAKE_ARGS=	CCNAME=${CC} CXXNAME=${CXX} PKGCFLAGS="${CFLAGS}" \
		INST_ETCDIR=${STAGEDIR}${PREFIX}/etc

# Just for debugging: Remove if possible.
MAKE_JOBS_UNSAFE=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	NCBI-VDB requires SSE2 instructions
BROKEN_i386=	buggy output

CFLAGS+=	-I${WRKSRC}/interfaces/os/sun
CXXFLAGS+=	-I${WRKSRC}/interfaces/os/sun
LDFLAGS+=	-lz

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

# for port developers, building with these options may fail
OPTIONS_DEFINE=	DEBUG OPTIMIZED_CFLAGS TEST
DEBUG_PREVENTS=	OPTIMIZED_CFLAGS
DEBUG_CONFIGURE_WITH=	debug
OPTIMIZED_CFLAGS_MAKE_ARGS_OFF=	OPT=""
TEST_TEST_TARGET=	test
TEST_USES=	python

xpre-patch:
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/build/
	@for f in ${WRKSRC}/build/ld.linux.*.sh; do ${CP} -p $${f} $${f%linux*}bsd$${f#*linux}; done
	@${CP} -p ${WRKSRC}/build/ld.linux.gcc.sh ${WRKSRC}/build/ld.bsd.clang.sh

pre-configure:
	${CP} ${NCBI_VDB_WRKSRC}/setup/os-arch.prl ${WRKSRC}/setup/os-arch.prl
	# same as in biology/ncbi-vdb
	@${CP} ${NCBI_VDB_FILESDIR}/Makefile.bsd ${WRKSRC}/build/
	@${CP} ${NCBI_VDB_WRKSRC}/build/ld.bsd.*.sh ${WRKSRC}/build/
	${MKDIR} ${WRKSRC}/interfaces/override
	@${CP} ${NCBI_VDB_WRKSRC}/interfaces/os/sun/atomic32.h ${WRKSRC}/interfaces/override
	@${CP} ${FILESDIR}/byteswap.h ${WRKSRC}/interfaces/override
	@for f in ${NCBI_VDB_WRKSRC}/build/ld.linux.*.sh; do ${CP} -p $${f} $${f%linux*}bsd$${f#*linux}; done
	@${CP} -p ${NCBI_VDB_WRKSRC}/build/ld.linux.gcc.sh ${WRKSRC}/build/ld.bsd.clang.sh
	#@${MKDIR} ${WRKSRC}/interfaces/os/bsd
	#@${CP} -p ${WRKSRC}/interfaces/os/mac/endian.h ${WRKSRC}/interfaces/os/bsd/
	${LN} -s ${NCBI_VDB_WRKSRC}/interfaces ${WRKSRC}/interfaces

post-patch-TEST-on:
	${REINPLACE_CMD} -e 's#python#${PYTHON_CMD}#' ${WRKSRC}/test/kget/Makefile

xpost-configure:
	@${ECHO} ${CHOSEN_COMPILER_TYPE} > ${WRKSRC}/build/COMP

post-build-TEST-on:	do-test

.include <bsd.port.mk>
