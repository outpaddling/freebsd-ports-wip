PORTNAME=	choreographer
DISTVERSION=	1.0.8
CATEGORIES=	wip www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Remote control of browsers from Python
WWW=		https://pypi.python.org/project/choreographer/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning>=0:devel/py-setuptools-git-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
