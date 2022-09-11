PORTNAME=	healpy
PORTVERSION=	1.7.4
CATEGORIES=	wip python
# https://pypi.python.org/packages/source/h/healpy/healpy-1.7.4.tar.gz
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python healpix maps tools
WWW=		https://pypi.python.org/pypi/healpy

LICENSE=	GPLv2

# C++11 or USE_GCC is a hack to find emmintrin.h and xmmintrin.h
USES=		compiler:c++11-lang pkgconfig python:3.6+
USE_PYTHON=	distutils

BUILD_DEPENDS+=	cython:lang/cython
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}pyfits>0:astro/py-pyfits

post-stage:
	for f in ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/healpy/*.so; do \
	${STRIP_CMD} $$f; \
	done

.include <bsd.port.mk>
