# $FreeBSD$

PORTNAME=	gemtools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	wip python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C API and a Python module to support usage of the GEM Mapper

# Check
LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=0:devel/py-argparse@${PY_FLAVOR}

USES=		compiler:openmp gmake python:2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils

post-patch:
	${RM} ${WRKSRC}/distribute_setup.py

.include <bsd.port.mk>
