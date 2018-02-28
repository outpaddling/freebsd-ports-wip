# $FreeBSD$

PORTNAME=	optparse
DISTVERSION=	1.3.2
CATEGORIES=	wip devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line parser inspired by Python's optparse

# 2 or 3
LICENSE=	GPLv2
#LICENSE_FILE=	

CRAN_DEPENDS=	R-cran-getopt>=1.19:wip/R-cran-getopt
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran

.include <bsd.port.mk>
