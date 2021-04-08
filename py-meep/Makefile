PORTNAME=	meep
PKGNAMEPREFIX=	python-
PORTVERSION=	1.4.2
CATEGORIES=	wip science
MASTER_SITES=	http://launchpad.net/python-meep/1.4/1.4/+download/
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Allows scripting of Meep-simulations with Python

# LICENSE=	gplv2, gplv3

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}

USES=		python:3.6+
USE_PYTHON=	distutils

# swig python-dev python-numpy python-scipy
BUILD_DEPENDS+=	swig:devel/swig13 \
		meep>=1.2:science/meep \
		${PYTHON_SITELIBDIR}/numpy:math/py-numpy \
		${PYTHON_SITELIBDIR}/scipy:science/py-scipy \
		${PYTHON_SITELIBDIR}/matplotlib:math/py-matplotlib

RUN_DEPENDS=	${BUILD_DEPENDS}

CFLAGS+=	-I${PYTHON_SITELIBDIR}/numpy/core/include
#CXXFLAGS+=	-I${PYTHON_SITELIBDIR}/numpy/core/include -fPIC
#LDFLAGS+=	-I${PYTHON_SITELIBDIR}/numpy/core/include -fPIC

post-patch:
		${MV} ${WRKSRC}/setup-mpi.py ${WRKSRC}/setup.py
		${REINPLACE_CMD} \
			-e 's|/usr/include|${LOCALBASE}/include|g' \
			-e 's|/usr/lib|${LOCALBASE}/lib|g' \
			-e 's|I:L:|I:L:c:|g' \
			-e "s|'help'|'help', 'single-version-externally-managed'|g" \
			${WRKSRC}/setup.py

.include <bsd.port.mk>
