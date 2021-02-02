# $FreeBSD$

PORTNAME=	libstempo
PORTVERSION=	2.2.5
CATEGORIES=	wip python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python wrapper for tempo2
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS+=	cython:lang/cython
LIB_DEPENDS=	libtempo2.so:wip/tempo2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

USES=		python:3.6+
USE_PYTHON=	distutils
USE_LDCONFIG=	yes
# Hack around compiler errors
USE_GCC=	any

# Hack around compiler errors
CFLAGS+=	-fpermissive

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/libstempo/libstempo.so

.include <bsd.port.mk>
