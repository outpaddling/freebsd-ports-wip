PORTNAME=	spectra
DISTVERSION=	0.1.0
CATEGORIES=	wip graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Color scales and color conversion made easy for Python
WWW=		https://pypi.python.org/pypi/spectra

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
# FIXME: colormath is no longer maintained.  Switch to fork colormath2.
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colormath>=3.0.0:math/py-colormath@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
