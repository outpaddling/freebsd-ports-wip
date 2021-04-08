PORTNAME=	ffc
# Caution: Must use version compatible with other FEniCS project ports
DISTVERSION=	2017.2.0
CATEGORIES=	wip math python
MASTER_SITES=	https://bitbucket.org/fenics-project/ffc/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Compiler for finite element variational forms

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PKGNAMEPREFIX}dijitso==${DV}:wip/py-dijitso@${PY_FLAVOR} \
		${PKGNAMEPREFIX}fiat==${DV}:wip/py-fiat@${PY_FLAVOR} \
		${PKGNAMEPREFIX}instant==${DV}:wip/py-instant@${PY_FLAVOR} \
		${PKGNAMEPREFIX}ufl==${DV}:wip/py-ufl@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

DV=		${DISTVERSION}

.include <bsd.port.mk>
