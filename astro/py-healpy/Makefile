# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	healpy
PORTVERSION=	1.7.4
CATEGORIES=	python
# https://pypi.python.org/packages/source/h/healpy/healpy-1.7.4.tar.gz
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Python healpix maps tools

LICENSE=	GPLv2

USES=		pkgconfig python
USE_PYTHON=	distutils

BUILD_DEPENDS+=	cython:${PORTSDIR}/lang/cython
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}pyfits>0:${PORTSDIR}/astro/py-pyfits

MAKE_JOBS_UNSAFE=	yes

post-stage:
	for f in ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/healpy/*.so; do \
	${STRIP_CMD} $$f; \
	done

.include <bsd.port.mk>
