# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	vcflib
PORTVERSION=	5f0fbe629593e5fb996a1a71201776424eef3834
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib \
		libtabix.so:/usr/wip/biology/tabixpp \
		libsw.so:/usr/wip/biology/smithwaterman
BUILD_DEPENDS=	fastahack>=0:/usr/wip/biology/fastahack \
		filevercmp>=0:/usr/wip/sysutils/filevercmp \
		fsom>=0:/usr/wip/biology/fsom \
		multichoose:/usr/wip/math/multichoose \
		intervaltree>=0:/usr/wip/math/intervaltree

# FIXME: compiler:openmp causes link error
USES=		gmake shebangfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

CXXFLAGS+=	-I${LOCALBASE}/include/smithwaterman \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/filevercmp \
		-I${LOCALBASE}/include/fastahack \
		-I${LOCALBASE}/include/intervaltree

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# GCC disables sse2 by default on i386, but it's required for vcflib
.if ${ARCH} == i386
CFLAGS+=	-msse2
.endif

# MAKE_JOBS_UNSAFE=	yes
MAKEFILE=		Makefile.external-libs
INSTALL_TARGET=		install-strip

.include <bsd.port.post.mk>
