# $FreeBSD$

PORTNAME=		srsly
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.0
CATEGORIES=		wip python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Modern high-performance serialization utilities for Python

LICENSE=	MIT

# Not sure about these
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0.24.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0.24.0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	explosion

.include <bsd.port.mk>
