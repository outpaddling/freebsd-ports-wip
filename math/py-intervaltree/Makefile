# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	intervaltree
PORTVERSION=	2.1.0
CATEGORIES=	python

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Mutable, self-balancing interval tree for Python

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	chaimleib
GH_TAGNAME=	${PORTVERSION}

USES=		python
USE_PYTHON=	distutils

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/sortedcontainers:devel/py-sortedcontainers

PIP_DESCR=	Use pip to build intervaltree
PIP_RUN_DEPENDS=	pip:devel/py-pip

MAKE_JOBS_UNSAFE=yes

#do-build:
#	cd ${WRKSRC} && ${MAKE} install-pypi
.include <bsd.port.mk>
