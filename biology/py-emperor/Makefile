# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# Do not upgrade this port beyond 0.x before testing with biology/py-qiime

PORTNAME=	emperor
PORTVERSION=	0.9.60
CATEGORIES=	biology
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
# DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Analysis, visualization and understanding of microbial ecology

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:math/py-numpy

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	emperor

.include <bsd.port.mk>
