
# FIXME: Need echo "backend: Agg" >> ~/.matplotlib/matplotlibrc
# to avoid "no matplotlib found" errors

PORTNAME=	illumina-utils
PORTVERSION=	2.3
CATEGORIES=	wip biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for Illumina paired-end data (for CASAVA 1.7+ pipeline)

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}levenshtein>0:devel/py-levenshtein@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
