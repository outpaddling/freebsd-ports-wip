PORTNAME=	htseq
DISTVERSIONPREFIX=	release_
DISTVERSION=	2.0.3
CATEGORIES=	wip biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Framework to analyze data from high-throughput sequencing assays
WWW=		https://pypi.python.org/pypi/HTSeq

LICENSE=	GPLv3

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.9.2:math/py-numpy@${PY_FLAVOR} \
		${PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		gmake python
USE_PYTHON=	autoplist cython distutils

USE_GITHUB=	yes

.include <bsd.port.mk>
