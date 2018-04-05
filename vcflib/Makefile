# $FreeBSD$

PORTNAME=	vcflib
DISTVERSION=	v1.0.0-rc1-130
DISTVERSIONSUFFIX=	-g7e3d806
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:biology/htslib \
		libtabix.so:wip/tabixpp \
		libsw.so:wip/smithwaterman
BUILD_DEPENDS=	fastahack>=0:wip/fastahack \
		filevercmp>=0:wip/filevercmp \
		fsom>=0:wip/fsom \
		multichoose:wip/multichoose \
		intervaltree>=0:wip/intervaltree
RUN_DEPENDS=	fastahack>=0:wip/fastahack \
		filevercmp>=0:wip/filevercmp \
		fsom>=0:wip/fsom \
		multichoose:wip/multichoose \
		intervaltree>=0:wip/intervaltree

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
	${LN} -s ${STAGEDIR}${PREFIX}/lib/libvcflib.so.1 \
		${STAGEDIR}${PREFIX}/lib/libvcflib.so

.include <bsd.port.mk>
