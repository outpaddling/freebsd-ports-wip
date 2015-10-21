# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	libstempo
PORTVERSION=	2.2.5
CATEGORIES=	python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Python wrapper for tempo2
# LICENSE=

BUILD_DEPENDS+=	cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=	libtempo2.so:/usr/wip/astro/tempo2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:${PORTSDIR}/math/py-numpy

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
