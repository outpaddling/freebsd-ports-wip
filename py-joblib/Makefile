PORTNAME=	joblib
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	wip devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Lightweight pipelining using Python functions as jobs
WWW=		https://joblib.readthedocs.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR}
TEST_DEPENDS=	${PYNUMPY}
#TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}threadpoolctl>0:devel/py-threadpoolctl@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

PYTEST_IGNORED_TESTS=	test_disk_used	\
			test_parallel_call_cached_function_defined_in_jupyter
PYTEST_BROKEN_TESTS=	test_memmapping_on_large_enough_dev_shm

.include <bsd.port.mk>
