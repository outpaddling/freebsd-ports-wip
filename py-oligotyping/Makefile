
PORTNAME=	oligotyping
DISTVERSION=	2.1
CATEGORIES=	wip biology
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Minimum entrop decomposition

LICENSE=	GPLv3

# R deps: http://merenlab.org/2014/08/16/installing-the-oligotyping-pipeline/
# 'vegan', 'ggplot2', 'gplots', 'gtools', 'reshape', 'optparse', 'pheatmap', 'RColorBrewer', 'compute.es'
# reshape or reshape2?
BUILD_DEPENDS=	${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy@${PY_FLAVOR} \
		${PKGNAMEPREFIX}matplotlib>=0.14.0:math/py-matplotlib@${PY_FLAVOR} \
		${PKGNAMEPREFIX}biopython>=1.60:biology/py-biopython@${PY_FLAVOR} \
		${PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS=	${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy@${PY_FLAVOR} \
		${PKGNAMEPREFIX}matplotlib>=0.14.0:math/py-matplotlib@${PY_FLAVOR} \
		${PKGNAMEPREFIX}biopython>=1.60:biology/py-biopython@${PY_FLAVOR} \
		${PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR} \
		R-cran-vegan>0:wip/R-cran-vegan \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-gtools>0:devel/R-cran-gtools \
		R-cran-reshape>0:devel/R-cran-reshape \
		R-cran-optparse>0:wip/R-cran-optparse \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		blastx:biology/ncbi-blast+

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
