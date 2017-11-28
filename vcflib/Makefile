# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vcflib
PORTVERSION=	2016.01.05
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

# FIXME: compiler:openmp causes link error
USES=		gmake shebangfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	790904320065e603c6af5b8a32f635134354467c

CXXFLAGS+=	-I${LOCALBASE}/include/smithwaterman \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/filevercmp \
		-I${LOCALBASE}/include/fastahack \
		-I${LOCALBASE}/include/intervaltree
# Hack for X120e
CFLAGS+=	-I/usr/include/clang/3.3

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# GCC disables sse2 by default on i386, but it's required for vcflib
.if ${ARCH} == i386
CFLAGS+=	-msse2
.endif

# MAKE_JOBS_UNSAFE=	yes
MAKEFILE=		Makefile.external-libs
INSTALL_TARGET=		install-strip

post-install:
	${CP} ${STAGEDIR}${PREFIX}/lib/libvcflib.so.1 \
		${STAGEDIR}${PREFIX}/lib/libvcflib.so

.include <bsd.port.post.mk>
