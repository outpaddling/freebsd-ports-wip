# Created by: Jason Bacon <bacon@oyster.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	eigensoft
PORTVERSION=	2015.09.17
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@oyster.jbacon.dyndns.org
COMMENT=

USES=		fortran gmake tar:xz

LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl \
		libopenblas.so:${PORTSDIR}/math/openblas

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

MAKE_ENV=	LOCALBASE=${LOCALBASE} FC=${FC}

# Just for debugging
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
