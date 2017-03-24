# Created by: Michael Danilov <mike.d.ft402@gmail.com>
# $FreeBSD$

PORTNAME=	mpi4py
PORTVERSION=	2.0.0
CATEGORIES=	net parallel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-openmpi

MAINTAINER=	bacon4000@gmail.com
COMMENT=	MPI for Python - Python bindings for MPI

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS?=	libmpi.so:net/openmpi

USE_GITHUB=	yes

USES=		python
USE_PYTHON=	distutils
NO_ARCH=	yes

CONFLICTS_INSTALL?=	py*-mpi4py-mpich-*

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	${CP} ${FILESDIR}/mpi.cfg ${WRKSRC}/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/docs ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${COPYTREE_SHARE} ${WRKSRC}/examples ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
