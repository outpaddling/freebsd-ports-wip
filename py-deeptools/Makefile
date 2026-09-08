PORTNAME=	deepTools
DISTVERSION=	4.0.0
CATEGORIES=	wip biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	deeptools-${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	User-friendly tools for exploring deep-sequencing data
WWW=		https://github.com/deeptools/deepTools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.10:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.23:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyBigWig>=0.3:biology/py-pybigwig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py2bit>=0.3:biology/py-py2bit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deeptoolsintervals>=0.1:biology/py-deeptoolsintervals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

# ./work-py312/deeptools-3.5.6/dist/deepTools-3.5.6-py3-none-any.whl
# ./work-py312/deeptools-4.0.0/dist/deeptools-4.0.0-cp312-cp312-freebsd_15_0_release_p13_amd64.whl
# ./work-py312/deeptools-4.0.0/target/wheels/deeptools-4.0.0-cp312-cp312-freebsd_15_0_release_p13_amd64.whl

# Doesn't work:
# PEP517_INSTALL_CMD=${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/dist/deeptools*.whl

# Doesn't work:
# pre-install:
# 	${CP} ${WRKSRC}/dist/deeptools-4.0.0-cp312-cp312-freebsd_15_0_release_p13_amd64.whl ${WRKSRC}/dist/deepTools-4.0.0-cp312-cp312-freebsd_15_0_release_p13_amd64.whl

.include <bsd.port.mk>
