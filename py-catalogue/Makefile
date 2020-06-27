# $FreeBSD$

PORTNAME=		catalogue
DISTVERSIONPREFIX=	v
DISTVERSION=		2.0.0
CATEGORIES=		wip python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Super lightweight function registries for your library

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes

GH_ACCOUNT=	explosion

.include <bsd.port.mk>
