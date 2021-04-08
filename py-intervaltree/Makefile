PORTNAME=	intervaltree
PORTVERSION=	2.1.0
CATEGORIES=	wip python

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Mutable, self-balancing interval tree for Python

LICENSE=	APACHE20

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	chaimleib

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/sortedcontainers:devel/py-sortedcontainers

.include <bsd.port.mk>
