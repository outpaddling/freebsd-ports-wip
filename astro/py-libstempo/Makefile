# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	libstempo
PORTVERSION=	2.2.5
CATEGORIES=	python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Python wrapper for tempo2
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS+=	cython:lang/cython
LIB_DEPENDS=	libtempo2.so:/usr/wip/astro/tempo2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

USES=		python
USE_PYTHON=	distutils
USE_LDCONFIG=	yes
# Hack around compiler errors
USE_GCC=	any

# Hack around compiler errors
CFLAGS+=	-fpermissive

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/libstempo/libstempo.so

.include <bsd.port.mk>
