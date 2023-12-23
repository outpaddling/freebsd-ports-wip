PORTNAME=	hmmlearn
DISTVERSION=	0.3.0
CATEGORIES=	wip math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unsupervised learning and inference of Hidden Markov Models
WWW=		https://github.com/hmmlearn/hmmlearn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.16:science/py-scikit-learn@${PY_FLAVOR} \
		wheel-${PYTHON_VER}:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.16:science/py-scikit-learn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYTHON_VER} --capture=no

.include <bsd.port.mk>
