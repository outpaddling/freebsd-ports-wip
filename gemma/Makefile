# $FreeBSD$

PORTNAME=	GEMMA
DISTVERSION=	0.98.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Efficient Mixed Model Association

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcblas.so:math/cblas \
		libgsl.so:math/gsl

USES=		blaslapack:openblas compiler:c++11-lang eigen:3 gmake \
		localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	genetics-statistics

MAKEFILE=	${FILESDIR}/Makefile
CXXFLAGS+=	-I${LOCALBASE}/include/eigen3 -DOPENBLAS -DOPENBLAS_LEGACY
LDFLAGS+=	-lopenblas

PLIST_FILES=	bin/gemma

.include <bsd.port.pre.mk>

# Force newer GCC on platforms using GCC 4.2 as base
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
