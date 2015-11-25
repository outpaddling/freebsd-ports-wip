# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	healpy
PORTVERSION=	1.7.4
CATEGORIES=	python
# https://pypi.python.org/packages/source/h/healpy/healpy-1.7.4.tar.gz
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Python healpix maps tools

LICENSE=	GPLv2

# C++11 or USE_GCC is a hack to find emmintrin.h and xmmintrin.h
USES=		compiler:c++11-lang pkgconfig python
USE_PYTHON=	distutils

BUILD_DEPENDS+=	cython:${PORTSDIR}/lang/cython
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}pyfits>0:${PORTSDIR}/astro/py-pyfits

post-stage:
	for f in ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/healpy/*.so; do \
	${STRIP_CMD} $$f; \
	done

.include <bsd.port.mk>
