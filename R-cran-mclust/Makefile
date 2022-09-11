PORTNAME=	mclust
DISTVERSION=	5.2.2
CATEGORIES=	wip math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Gaussian finite mixture models fitted via EM algorithm
WWW=		https://cran.r-project.org/web/packages/mclust/

LICENSE=	GPLv2
#LICENSE_FILE=

USES=		cran:auto-plist fortran

# Not working
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/R/lib

.include <bsd.port.mk>
