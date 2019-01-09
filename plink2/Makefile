# $FreeBSD$

PORTNAME=		plink-ng
DISTVERSIONPREFIX=	v
DISTVERSION=		g20190108
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	libcblas.so:math/cblas \
		libopenblas.so:math/openblas

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	Tests/*.sh Tests/*/*.sh
GH_ACCOUNT=	chrchang
GH_TAGNAME=	04c8182

MAKEFILE=	${FILESDIR}/Makefile.generic
WRKSRC_SUBDIR=	2.0
CFLAGS+=	-DDYNAMIC_ZLIB
CXXFLAGS+=	-DDYNAMIC_ZLIB
LDFLAGS+=	-lpthread
MAKE_ARGS+=	ZLIB=-lz BLASFLAGS64="-L${LOCALBASE}/lib -lopenblas -lgfortran"
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/plink2 bin/pgen_compress

.include <bsd.port.mk>
