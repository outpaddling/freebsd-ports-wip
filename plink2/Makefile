# $FreeBSD$

PORTNAME=		plink-ng
DISTVERSIONPREFIX=	v
DISTVERSION=		g20180521
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	libcblas.so:math/cblas \
		libopenblas.so:math/openblas

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake shebangfix
SHEBANG_FILES=	Tests/*.sh Tests/*/*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng
GH_TAGNAME=	0ad8bbb191a98b8a4549799b174462607da99018

MAKEFILE=	${FILESDIR}/Makefile.generic
WRKSRC_SUBDIR=	2.0
CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
LDFLAGS+=	-lpthread
MAKE_ARGS+=	ZLIB=-lz BLASFLAGS64="-L${LOCALBASE}/lib -lopenblas -lgfortran"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		AVX NATIVE_CPU SSE42 SSE_NATIVE
AVX_DESC=		Force AVX (build non-portable binaries)
NATIVE_CPU_DESC=	Optimize for this CPU (build non-portable binaries)
SSE42_DESC=		Force SSE4.2 (build non-portable binaries)
SSE_NATIVE_DESC=	Optimize for this CPU (build non-portable binaries)
AVX_CFLAGS=		-mavx -mbmi
NATIVE_CPU_CFLAGS=	-march=native
SSE42_CFLAGS=		-msse4.2
SSE_NATIVE_CFLAGS=	-mfpmath=sse -msse3 -march=native

PLIST_FILES=	bin/plink2 bin/pgen_compress

.include <bsd.port.mk>
