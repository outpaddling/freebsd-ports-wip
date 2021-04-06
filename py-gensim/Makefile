
PORTNAME=	gensim
PORTVERSION=	2.2.0
CATEGORIES=	wip python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python library for topic modeling, document indexing, etc

LICENSE=	LGPL21
# LICENSE_FILE=

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CFLAGS+=	-I${PYTHON_SITELIBDIR}/numpy/core/include

.include <bsd.port.mk>
