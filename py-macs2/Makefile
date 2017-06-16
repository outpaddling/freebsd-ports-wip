# Created by: Charlie %%FULLNAME%% <root@freebsd-10.1.local>
# $FreeBSD$

PORTNAME=	MACS2
PORTVERSION=	2.1.0.20150420.1
CATEGORIES=	wip biology
MASTER_SITES=	http://pypi.python.org/packages/source/M/MACS2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Novel algorithm for identifying transcript factor binding sites

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	macs2

WRKSRC=		${WRKDIR}/${PORTNAME}-2.1.0.20150420

post-stage:
		${STRIP_CMD} \
			${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*.so \
			${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*/*.so

.include <bsd.port.mk>
