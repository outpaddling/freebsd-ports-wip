# $FreeBSD$

PORTNAME=	vcflib
PORTVERSION=	1.0.0p20180208
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
GH_TAGNAME=	7e3d8066a6c6c0f22191a70d050ead23f9c453b3

CXXFLAGS+=	-I${LOCALBASE}/include/smithwaterman \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/filevercmp \
		-I${LOCALBASE}/include/fastahack \
		-I${LOCALBASE}/include/intervaltree \
		-DVERSION='\"${PORTVERSION}\"'

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
.if ${ARCH} == i386
CFLAGS+=	-msse2
.endif

MAKEFILE=		Makefile.external-libs
INSTALL_TARGET=		install-strip

post-patch:
	${CP} ${FILESDIR}/Makefile.external-libs ${WRKSRC}

post-install:
	${CP} ${STAGEDIR}${PREFIX}/lib/libvcflib.so.1 \
		${STAGEDIR}${PREFIX}/lib/libvcflib.so

.include <bsd.port.post.mk>
