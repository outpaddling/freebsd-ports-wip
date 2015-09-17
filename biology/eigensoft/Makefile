# Created by: Jason Bacon <bacon@oyster.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	eigensoft
PORTVERSION=	2015.09.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@oyster.jbacon.dyndns.org
COMMENT=

USES=		fortran tar:xz

# GSL, openblas, fortran
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl \
		libblas.so:${PORTSDIR}/math/blas

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
