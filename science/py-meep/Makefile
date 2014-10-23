# Created by: Jason Bacon <bacon@tocino.cs.uwm.edu>
# $FreeBSD$

PORTNAME=	meep
PKGNAMEPREFIX=	python-
PORTVERSION=	1.4.2
CATEGORIES=	science
MASTER_SITES=	http://launchpad.net/python-meep/1.4/1.4/+download/
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	jwbacon@tds.net
COMMENT=	Allows scripting of Meep-simulations with Python

# LICENSE=	gplv2, gplv3

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}

USES=		python
USE_PYTHON=	distutils

# swig python-dev python-numpy python-scipy
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13 \
		meep>=1.2:${PORTSDIR}/science/meep \
		${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${PYTHON_SITELIBDIR}/matplotlib:${PORTSDIR}/math/py-matplotlib

RUN_DEPENDS=	${BUILD_DEPENDS}

CFLAGS+=	-I${PYTHON_SITELIBDIR}/numpy/core/include

post-patch:
		${MV} ${WRKSRC}/setup-mpi.py ${WRKSRC}/setup.py
		${REINPLACE_CMD} \
			-e 's|/usr/include|${LOCALBASE}/include|g' \
			-e 's|/usr/lib|${LOCALBASE}/lib|g' \
			${WRKSRC}/setup.py

.include <bsd.port.mk>
