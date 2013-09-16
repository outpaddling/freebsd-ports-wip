# New ports collection makefile for:	armadillo
# Date created:		2011-08-14
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	armadillo
PORTVERSION=	3.6.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arma/}

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ template matrix library

LIB_DEPENDS=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack \
		boost_math_c99:${PORTSDIR}/devel/boost-libs

USE_CMAKE=	yes
USE_FORTRAN=	yes
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/Aramdillo

# Disable search for optional components to ensure consistent build
post-patch:
	${REINPLACE_CMD} \
		-e 's|include(ARMA_FindMKL)|# include(ARMA_FindMKL)|g' \
		-e 's|include(ARMA_FindACMLMP)|# include(ARMA_FindACMLMP)|g' \
		-e 's|include(ARMA_FindACML)|# include(ARMA_FindACML)|g' \
		-e 's|include(ARMA_FindCLAPACK)|# include(ARMA_FindCLAPACK)|g' \
		-e 's|include(ARMA_FindCBLAS)|# include(ARMA_FindCBLAS)|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
