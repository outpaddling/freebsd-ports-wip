PORTNAME=	khmer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.2
CATEGORIES=	wip python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command-line tools for working with DNA shotgun sequencing data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bz2file>=0.98:archivers/py-bz2file@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython distutils
USE_GITHUB=	yes

GH_ACCOUNT=	dib-lab

.include <bsd.port.mk>
