PORTNAME=	catalogue
# Do not use latest release.  See acceptable versions in py-spacy setup.cfg.
DISTVERSION=	1.0.0
CATEGORIES=	wip python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Super lightweight function registries for your library
WWW=		https://pypi.python.org/pypi/catalogue

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
