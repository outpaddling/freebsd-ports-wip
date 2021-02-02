# $FreeBSD: head/archivers/py-xopen/Makefile 500186 2019-04-27 01:22:33Z jwb $

PORTNAME=	xopen
DISTVERSION=	1.0.0	# py-cutadapt requires exactly 1.0.0
CATEGORIES=	wip archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open compressed files transparently

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bz2file>=0.98:archivers/py-bz2file@${PY_FLAVOR} \
		pigz>=0:archivers/pigz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
