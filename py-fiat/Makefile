# $FreeBSD: head/math/py-fiat/Makefile 460452 2018-01-31 01:07:07Z jwb $

PORTNAME=	fiat
# Caution: Must use version compatible with other FEniCS project ports
DISTVERSION=	2017.2.0
CATEGORIES=	wip math python
MASTER_SITES=	https://bitbucket.org/fenics-project/fiat/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	FInite element Automatic Tabulator

LICENSE=	LGPL3

# BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scientific>=0:math/py-scientific@${PY_FLAVOR}
# RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
