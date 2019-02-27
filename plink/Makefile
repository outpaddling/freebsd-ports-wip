# $FreeBSD$

PORTNAME=		plink
DISTVERSIONPREFIX=	v
DISTVERSION=		g20190227
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	libcblas.so:math/cblas \
		liblapack.so:math/lapack \
		libblas.so:math/blas

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake

USE_GITHUB=	yes
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng
GH_TAGNAME=	464bfd4

WRKSRC_SUBDIR=	1.9
CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
LDFLAGS+=	-lpthread
MAKE_ARGS=	ZLIB=-lz BLASFLAGS="-L${LOCALBASE}/lib -llapack -lcblas -lblas -lgfortran"
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/plink

post-patch:
	${CP} ${WRKSRC}/Makefile.std ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
