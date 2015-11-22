# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	emperor
PORTVERSION=	0.9.3
CATEGORIES=	biology
MASTER_SITES=	http://pypi.python.org/packages/source/e/emperor/
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
# DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Analysis, visualization and understanding of microbial ecology

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	emperor

.include <bsd.port.mk>
