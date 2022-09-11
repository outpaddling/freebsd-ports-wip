PORTNAME=	vegan
DISTVERSION=	2.4-2
CATEGORIES=	wip biology
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ordination methods, diversity analysis etc for ecologists
WWW=		https://cran.r-project.org/web/packages/vegan/

LICENSE=	GPLv2
#LICENSE_FILE=	

# Depends: 	permute (≥ 0.9-0), lattice, R (≥ 3.0.0)
# Imports: 	MASS, cluster, mgcv
# Suggests: 	parallel, tcltk, knitr

# R-cran-lattice is in the R base
CRAN_DEPENDS=	R-cran-permute>=0.9-0:wip/R-cran-permute
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
