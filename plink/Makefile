# $FreeBSD$

PORTNAME=		plink19
DISTVERSIONPREFIX=	v
DISTVERSION=		1.90b4
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	libopenblas.so:math/openblas

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake

USE_GITHUB=	yes
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng
GH_TAGNAME=	cbcf442c176036138419b14d6b46a3d57e8325d4

WRKSRC_SUBDIR=	1.9
CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
LDFLAGS+=	-lpthread
MAKE_ARGS+=	ZLIB=-lz BLASFLAGS="-L${LOCALBASE}/lib -lopenblas"
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/plink19

post-patch:
	${CP} ${WRKSRC}/Makefile.std ${WRKSRC}/Makefile

# Override install target and install as plink1 to allow coexistence with
# plink 1.07
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${STAGEDIR}${PREFIX}/bin/plink19

.include <bsd.port.mk>
