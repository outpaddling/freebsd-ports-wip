# Created by: Jason Bacon <bacon@sculpin.acadix.biz>
# $FreeBSD$

PORTNAME=	oligotyping
PORTVERSION=	1.7
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
CATEGORIES=	biology
MASTER_SITES=	http://oligotyping.org/files/downloads/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Minimum entrop decomposition

# Deps:
# http://oligotyping.org/2014/08/16/installing-the-oligotyping-pipeline/
# py27-pip py27-scipy py27-matplotlib py27-biopython py27-django git
# R: 'vegan', 'ggplot2', 'gplots', 'gtools', 'reshape', 'optparse', 'pheatmap', 'RColorBrewer', 'compute.es'
# BLAST+

USES=		python:2 shebangfix
USE_PYTHON=	distutils
#SHEBANG_FILES=	scripts/ec2Clean scripts/ec2Dispatch

BUILD_DEPENDS=	${PKGNAMEPREFIX}pip>=6.0.6:${PORTSDIR}/devel/py-pip \
		${PKGNAMEPREFIX}scipy>=0.14.0:${PORTSDIR}/science/py-scipy \
		${PKGNAMEPREFIX}matplotlib>=0.14.0:${PORTSDIR}/math/py-matplotlib \
		${PKGNAMEPREFIX}biopython>=1.60:${PORTSDIR}/biology/py-biopython \
		${PKGNAMEPREFIX}django>=1.7:${PORTSDIR}/www/py-django \
		${PKGNAMEPREFIX}mock>=1.0.1:${PORTSDIR}/devel/py-mock

# No R-cran-vegan, gplots, optparse, pheatmap, compute-es
RUN_DEPENDS=	${BUILD_DEPENDS} \
		R-cran-ggplot2>0:${PORTSDIR}/graphics/R-cran-ggplot2 \
		R-cran-gtools>0:${PORTSDIR}/devel/R-cran-gtools \
		R-cran-reshape>0:${PORTSDIR}/devel/R-cran-reshape \
		R-cran-RColorBrewer>0:${PORTSDIR}/graphics/R-cran-RColorBrewer \
		blastx:${PORTSDIR}/biology/ncbi-blast+

.include <bsd.port.mk>
