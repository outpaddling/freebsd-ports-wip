PORTNAME=	deepTools
DISTVERSION=	3.5.1
CATEGORIES=	wip python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	User-friendly tools for exploring deep-sequencing data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.17.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.3.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.14.0:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py2bit>=0.2.0:wip/py-2bit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=0.5:textproc/py-numpydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyBigWig>=0.2.1:wip/py-bigwig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=4.9:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deeptoolsintervals>=0.1.8:wip/py-deeptoolsintervals@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
