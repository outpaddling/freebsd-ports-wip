# Do not upgrade this port beyond 0.2.x before testing with biology/py-qiime

PORTNAME=	scikit-bio
PORTVERSION=	0.2.3
CATEGORIES=	wip biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Data structures, algorithms and educational resources for bioinformatics
WWW=		https://pypi.python.org/pypi/scikit-bio

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

# Not sure about clauses
LICENSE=	BSD2CLAUSE
# LICENSE_FILE=	

USES=		fortran python:2
USE_PYTHON=	distutils

.include <bsd.port.mk>
