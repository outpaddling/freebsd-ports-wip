PORTNAME=	poretools
DISTVERSION=	0.6.0
CATEGORIES=	wip python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Toolkit for working with nanopore sequencing data from Oxford Nanopore
WWW=		https://pypi.python.org/pypi/poretools

LICENSE=	MIT

LIB_DEPENDS=	libhdf5.so:science/hdf5
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=2.2.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seaborn>=0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	poretools/*.py poretools/scripts/poretools

.include <bsd.port.mk>
