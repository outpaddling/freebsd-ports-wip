# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	idr
DISTVERSION=	2.0.3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Estimating the copula mixture model and plotting correspondence curves

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

USES=		python:3
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	nboley

.include <bsd.port.mk>
