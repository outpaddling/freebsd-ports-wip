
PORTNAME=	biom
# Version 1.3.1 is specifically listed as a dep for qiime
PORTVERSION=	1.3.1
CATEGORIES=	wip biology
#MASTER_SITES=	http://github.com/biocore/biom-format/archive/
MASTER_SITES=	http://pypi.python.org/packages/source/b/biom-format/
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-format
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	The Biological Observation Matrix (BIOM) Format Project

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:math/py-numpy

USES=		python:3.6+
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	biom
# --single-version-externally-managed not recognized on 9.x
# PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --root=${STAGEDIR}

.include <bsd.port.mk>
