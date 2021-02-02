# $FreeBSD$

PORTNAME=	scikit-bio
PORTVERSION=	0.5.5
CATEGORIES=	wip biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Data structures, algorithms, educational resources for bioinformatics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

USES=		fortran python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
