PORTNAME=	ncbi-vdb
DISTVERSION=	2.10.9
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's virtualized back-end for accessing Sequence Read Archive

LICENSE=	PD LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =	${DISTNAME}${EXTRACT_SUFX}

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libmbedtls.so:security/mbedtls

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi
GH_TUPLE+=	ncbi:ngs:1.3.0:ngs

USES=		gmake perl5 shebangfix
USE_PERL5=	build
SHEBANG_GLOB=	*.sh *.pl

GNU_CONFIGURE=	yes

# for port developpers, building with these options may fail
OPTIONS_DEFINE=	DEBUG GCC OPTIMIZED_CFLAGS TEST
DEBUG_PREVENTS=	OPTIMIZED_CFLAGS
DEBUG_CONFIGURE_WITH=	debug
GCC_USE=	gcc=yes
OPTIMIZED_CFLAGS_MAKE_ARGS_OFF=	OPT=""
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
