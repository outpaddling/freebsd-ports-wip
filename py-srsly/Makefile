PORTNAME=	srsly
# Do not use latest release.  See acceptable versions in py-spacy setup.cfg.
DISTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	wip devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Modern high-performance serialization utilities for Python
WWW=		https://github.com/explosion/srsly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist cython distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/srsly/*/*.so

.include <bsd.port.mk>
