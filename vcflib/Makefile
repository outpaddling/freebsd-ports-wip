# $FreeBSD$

PORTNAME=		vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.0-rc1-130
DISTVERSIONSUFFIX=	-g7e3d806
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:biology/htslib \
		libtabix.so:biology/tabixpp \
		libsw.so:biology/smithwaterman
COMMON_DEPENDS=	fastahack:biology/fastahack \
		filevercmp:sysutils/filevercmp \
		fsom:wip/fsom \
		multichoose>=1.0.3:wip/multichoose \
		interval_tree_test:wip/intervaltree
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		gmake shebangfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ekg

CXXFLAGS+=	-I${LOCALBASE}/include/smithwaterman \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/filevercmp \
		-I${LOCALBASE}/include/fastahack \
		-I${LOCALBASE}/include/intervaltree \
		-DVERSION='\"${PORTVERSION}\"'

INSTALL_TARGET=	install-strip

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

MAKEFILE=		Makefile.external-libs
INSTALL_TARGET=		install-strip

post-patch:
	${CP} ${FILESDIR}/Makefile.external-libs ${WRKSRC}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libvcflib.so.1 \
		${STAGEDIR}${PREFIX}/lib/libvcflib.so

.include <bsd.port.mk>
