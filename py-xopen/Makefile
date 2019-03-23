# $FreeBSD$

PORTNAME=	xopen
DISTVERSION=	0.5.0
CATEGORIES=	wip archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open compressed files transparently

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bz2file>=0.98:archivers/py-bz2file@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
