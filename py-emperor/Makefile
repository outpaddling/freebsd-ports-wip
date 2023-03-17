# Do not upgrade this port beyond 0.x before testing with biology/py-qiime

PORTNAME=	emperor
PORTVERSION=	0.9.60
CATEGORIES=	wip biology
MASTER_SITES=	PYPI
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
# DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Analysis, visualization and understanding of microbial ecology
WWW=		https://github.com/biocore/biom-format

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:math/py-numpy

USES=		python:3.6+
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	emperor

.include <bsd.port.mk>
