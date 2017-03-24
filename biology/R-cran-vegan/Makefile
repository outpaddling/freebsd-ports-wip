# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	vegan
DISTVERSION=	2.4-2
CATEGORIES=	biology
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Ordination methods, diversity analysis etc for ecologists

LICENSE=	GPLv2
#LICENSE_FILE=	

# Depends: 	permute (≥ 0.9-0), lattice, R (≥ 3.0.0)
# Imports: 	MASS, cluster, mgcv
# Suggests: 	parallel, tcltk, knitr

# R-cran-lattice is in the R base
CRAN_DEPENDS=	R-cran-permute>=0.9-0:/usr/wip/math/R-cran-permute
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
