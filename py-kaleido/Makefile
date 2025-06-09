PORTNAME=		kaleido
DISTVERSION=		1.0.0
DISTVERSIONSUFFIX=	rc11
CATEGORIES=		wip graphics python
MASTER_SITES=		PYPI
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Cross-platform library for generating static images for Plotly
WWW=		https://pypi.python.org/project/kaleido/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# TODO: Add py-choreographer dep.  Only works with chrome as of 2025-06-09.
# https://github.com/plotly/choreographer
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning>=0:devel/py-setuptools-git-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=0:devel/py-async_timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
