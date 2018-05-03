# $FreeBSD$

PORTNAME=		plink-ng
DISTVERSIONPREFIX=	v
DISTVERSION=		g20180428
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	liblapack.so:math/lapack \
		libcblas.so:math/cblas \
		libopenblas.so:math/openblas

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake
USE_GITHUB=	yes
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng
GH_TAGNAME=	d046d8dfbbba50065644bbe9647edbe94a29b1a2

WRKSRC_SUBDIR=	2.0
CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
LDFLAGS+=	-lpthread
MAKE_ARGS+=	ZLIB=-lz BLASFLAGS64="-L${LOCALBASE}/lib -lopenblas"
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/plink2 bin/pgen_compress

.include <bsd.port.mk>
