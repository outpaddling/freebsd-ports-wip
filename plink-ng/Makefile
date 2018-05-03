# $FreeBSD$

PORTNAME=		plink-ng
DISTVERSIONPREFIX=	v
DISTVERSION=		g20180502
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	libcblas.so:math/cblas \
		libopenblas.so:math/openblas

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake
USE_GITHUB=	yes
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng
#GH_TAGNAME=	d046d8dfbbba50065644bbe9647edbe94a29b1a2
GH_TAGNAME=	3dbb2ba332efe585056ed9b1d3d8c03e870e379e

WRKSRC_SUBDIR=	2.0
CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
LDFLAGS+=	-lpthread
MAKE_ARGS+=	ZLIB=-lz BLASFLAGS64="-L${LOCALBASE}/lib -lopenblas -lgfortran"
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/plink2 bin/pgen_compress

.include <bsd.port.mk>
