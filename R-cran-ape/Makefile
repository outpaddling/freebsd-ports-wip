# $FreeBSD$

PORTNAME=	ape
DISTVERSION=	5.4-1
CATEGORIES=	wip biology
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	bacon@imacbsd.acadix.biz
COMMENT=	Functions for phylogenetic trees

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# Imports:
# nlme, lattice, graphics, methods, stats, tools, utils, parallel,
# Rcpp (>= 0.12.0)
# Most seem to be in the R default install (all load successfully)
CRAN_DEPENDS=	R-cran-Rcpp>=0.12.0:math/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
