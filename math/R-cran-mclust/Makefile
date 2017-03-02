# Created by: Jason Bacon <bacon@imacbsd.acadix.biz>
# $FreeBSD$

PORTNAME=	mclust
DISTVERSION=	5.2.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	bacon@imacbsd.acadix.biz
COMMENT=	Gaussian finite mixture models fitted via EM algorithm

LICENSE=	GPLv2
#LICENSE_FILE=

#USES=		cran:auto-plist fortran
USES=		cran fortran

# Not working
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/R/lib

.include <bsd.port.mk>
