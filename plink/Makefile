# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/biology/plink/Makefile 437439 2017-04-01 15:23:30Z gerald $

PORTNAME=	plink
PORTVERSION=	1.90b4
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology science

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	liblapack.so:math/lapack \
		libcblas.so:math/cblas \
		libopenblas.so:math/openblas

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake
# Need to compile C files with C++ compiler, which clang complains about
USE_GCC=	yes

USE_GITHUB=	yes
#GH_ACCOUNT=	chrchang
GH_ACCOUNT=	outpaddling
GH_PROJECT=	plink-ng
GH_TAGNAME=	381b8f1cd1a1ab502b486405069f2295b851843a

#WRKSRC=	${WRKDIR}/${PORTNAME}-ng-${PORTVERSION}/1.9
WRKSRC=		${WRKDIR}/${PORTNAME}-ng-${GH_TAGNAME}/1.9

CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
CXXFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
LDFLAGS+=	-lpthread

# Override defaults in Makefile.generic
MAKE_FLAGS+=	ZLIB=-lz BLASFLAGS="-L${LOCALBASE}/lib -llapack -lcblas -lopenblas"

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/plink19

post-patch:
	${CP} ${WRKSRC}/Makefile.generic ${WRKSRC}/Makefile

# Override install target and install as plink1 to allow coexistence with
# plink 1.07
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${STAGEDIR}${PREFIX}/bin/plink19

.include <bsd.port.mk>
