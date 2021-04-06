
PORTNAME=	ufl
# Caution: Must use version compatible with other FEniCS project ports
DISTVERSION=	2017.2.0
CATEGORIES=	wip math python
MASTER_SITES=	https://bitbucket.org/fenics-project/ufl/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unified Form Language for finite element discretizations

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
