PORTNAME=	fenics
PORTVERSION=	2017.2.0
CATEGORIES=	wip math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Computing platform for solving partial differential equations
WWW=		https://fenicsproject.org/

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dijitso==${PORTVERSION}:wip/py-dijitso \
		${PYTHON_PKGNAMEPREFIX}ffc==${PORTVERSION}:wip/py-ffc \
		${PYTHON_PKGNAMEPREFIX}fiat==${PORTVERSION}:wip/py-fiat \
		${PYTHON_PKGNAMEPREFIX}instant==${PORTVERSION}:wip/py-instant \
		${PYTHON_PKGNAMEPREFIX}ufl==${PORTVERSION}:wip/py-ufl \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib \
		dolfin==${PORTVERSION}:wip/dolfin \
		mshr==${PORTVERSION}:wip/mshr

USE_PYTHON=	flavors

USES=		metaport python:3.6+

.include <bsd.port.mk>
