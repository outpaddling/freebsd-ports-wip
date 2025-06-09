PORTNAME=		kaleido
# The kaleido situation is currently a mess.  One of it's goals it to
# reduce dependencies vs using orca + psutil, but kaleido depends on
# the chrome browser.  Additionally, rc115 conflicts with its own
# dependency, py-choreographer 1.0.8.  I plan to let the dust settle
# before committing this to ports.
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

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning>=0:devel/py-setuptools-git-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}choreographer>=0:wip/py-choreographer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
