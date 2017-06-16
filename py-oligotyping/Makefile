# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	oligotyping
PORTVERSION=	1.7
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
CATEGORIES=	wip biology
MASTER_SITES=	http://oligotyping.org/files/downloads/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Minimum entrop decomposition

# Deps:
# http://oligotyping.org/2014/08/16/installing-the-oligotyping-pipeline/
# py27-pip py27-scipy py27-matplotlib py27-biopython py27-django git
# R: 'vegan', 'ggplot2', 'gplots', 'gtools', 'reshape', 'optparse', 'pheatmap', 'RColorBrewer', 'compute.es'
# BLAST+

USES=		python:2 shebangfix
USE_PYTHON=	distutils
#SHEBANG_FILES=	scripts/ec2Clean scripts/ec2Dispatch

BUILD_DEPENDS=	${PKGNAMEPREFIX}pip>=6.0.6:devel/py-pip \
		${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy \
		${PKGNAMEPREFIX}matplotlib>=0.14.0:math/py-matplotlib \
		${PKGNAMEPREFIX}biopython>=1.60:biology/py-biopython \
		${PKGNAMEPREFIX}django>=1.7:www/py-django \
		${PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock

# No R-cran-vegan, gplots, optparse, pheatmap, compute-es
RUN_DEPENDS=	${BUILD_DEPENDS} \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-gtools>0:devel/R-cran-gtools \
		R-cran-reshape>0:devel/R-cran-reshape \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		blastx:biology/ncbi-blast+

.include <bsd.port.mk>
