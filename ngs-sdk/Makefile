
PORTNAME=	ngs
PORTVERSION=	1.3.0
CATEGORIES=	wip biology
PKGNAMESUFFIX=	-sdk

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	NCBI's front-end API for NGS data manipulation

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/../LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

USES=		compiler gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CXX="${CXX}" TOOLS="${CHOSEN_COMPILER_TYPE}"
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	ngs-sdk
ALL_TARGET=	subtargs

# for port developpers, building with these options may fail
OPTIONS_DEFINE=	EXAMPLES GCC DEBUG OPTIMIZED_CFLAGS TEST
DEBUG_PREVENTS=	OPTIMIZED_CFLAGS
DEBUG_CONFIGURE_WITH=	debug
GCC_USE=	gcc=yes
OPTIMIZED_CFLAGS_MAKE_ARGS_OFF=	OPT=""
TEST_TEST_TARGET=	test

post-build-TEST-on:	do-test

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f Makefile.install ${MAKE_ARGS} copylibs copyincludes)

post-install-EXAMPLES-on:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f Makefile.install ${MAKE_ARGS} copyexamples)

.include <bsd.port.mk>
