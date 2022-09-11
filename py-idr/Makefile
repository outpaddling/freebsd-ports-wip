PORTNAME=	idr
DISTVERSION=	2.0.3
CATEGORIES=	wip math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Estimating the copula mixture model and plotting correspondence curves
WWW=		https://cran.r-project.org/web/packages/idr/index.html

LICENSE=	GPLv2

# py-matplotlib does not build under py34 as of 2016-06-22
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:wip/py3-matplotlib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:wip/py3-matplotlib

USES=		python:3.6+
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	nboley

.include <bsd.port.mk>
