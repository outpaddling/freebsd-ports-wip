# $FreeBSD$

PORTNAME=	oligotyping
DISTVERSION=	2.1
CATEGORIES=	wip biology
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Minimum entrop decomposition

LICENSE=	GPLv3

BUILD_DEPENDS=	${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy@${PY_FLAVOR} \
		${PKGNAMEPREFIX}matplotlib>=0.14.0:math/py-matplotlib@${PY_FLAVOR} \
		${PKGNAMEPREFIX}biopython>=1.60:biology/py-biopython@${PY_FLAVOR} \
		${PKGNAMEPREFIX}django>=1.7:www/py-django111@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS=	${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy@${PY_FLAVOR} \
		${PKGNAMEPREFIX}matplotlib>=0.14.0:math/py-matplotlib@${PY_FLAVOR} \
		${PKGNAMEPREFIX}biopython>=1.60:biology/py-biopython@${PY_FLAVOR} \
		${PKGNAMEPREFIX}django>=1.7:www/py-django111@${PY_FLAVOR}

#		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
#		R-cran-gtools>0:devel/R-cran-gtools \
#		R-cran-reshape>0:devel/R-cran-reshape \
#		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
#		blastx:biology/ncbi-blast+

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
