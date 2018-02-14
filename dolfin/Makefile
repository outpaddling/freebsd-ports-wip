# $FreeBSD$

PORTNAME=	dolfin
PORTVERSION=	2017.2.0
CATEGORIES=	wip
MASTER_SITES=	https://bitbucket.org/fenics-project/dolfin/downloads/

MAINTAINER=	bacon@manatee.acadix.biz
COMMENT=	Computational backend of FEniCS

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	eigen>0:math/eigen3 \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ffc>0:wip/py-ffc@${FLAVOR} \
		swig30>0:devel/swig30
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libboost_math_c99.so:devel/boost-libs

USES=		cmake:outsource pkgconfig python

.include <bsd.port.mk>
