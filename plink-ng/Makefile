# $FreeBSD$

PORTNAME=		plink-ng
DISTVERSIONPREFIX=	v
DISTVERSION=		g20180503
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
GH_TAGNAME=	e81056a32d67cd73a69579e2dbb374d16196f305

WRKSRC_SUBDIR=	2.0
CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include -g
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include -g
LDFLAGS+=	-lpthread
MAKE_ARGS+=	ZLIB=-lz BLASFLAGS64="-L${LOCALBASE}/lib -lopenblas -lgfortran"
# INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/plink2 bin/pgen_compress

.include <bsd.port.mk>
