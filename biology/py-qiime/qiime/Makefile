# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	qiime
PORTVERSION=	1.8.0
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
CATEGORIES=	biology
MASTER_SITES=	http://github.com/biocore/qiime/archive/ \
		http://www.drive5.com/uclust/
DISTFILES=	${PORTVERSION}${EXTRACT_SUFX} \
		uclustq1.2.22_i86linux32
EXTRACT_ONLY=	${PORTVERSION}${EXTRACT_SUFX}
MAINTAINER=	jwbacon@tds.net
COMMENT=	Quantitative Insights Into Microbial Ecology

# uclust is a Linux closed-source binary and required for qiime
ONLY_FOR_ARCH=	i386 amd64

USES=		python:2
USE_PYTHON=	distutils

PYDISTUTILS_PKGNAME=	qiime

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.5.1:${PORTSDIR}/math/py-numpy \
		${PKGNAMEPREFIX}matplotlib>=1.1.0:${PORTSDIR}/math/py-matplotlib \
		pycogent>=1.1.0:${PORTSDIR}/biology/pycogent \
		${PKGNAMEPREFIX}biom-format>=1.3.1:/usr/wip/biology/py-biom-format
RUN_DEPENDS=	${BUILD_DEPENDS}

# http://qiime.org/install/install.html
# Canopy Express
#    Python 2.7.3, numpy 1.5.1 - 1.7.1, MatPlotLib 1.1.0 - 1.3.1
#    /usr/ports/math/py-numpy 1.8.1
#    /usr/ports/math/py-matplotlib 1.4.0
# Other
#    pycogent 1.5.3, biom-format 1.3.1, qcli 0.1.0, pynast 1.2.2, emporer 0.9.3
#    /usr/ports/biology/pycogent 1.5.3
#    /usr/wip/biology/py-biom-format 2.0.1
#    
# Non-python
#    uclust 1.2.22q, fasttree 2.1.3

.include <bsd.port.mk>
