PORTNAME=	mpi4py
PORTVERSION=	2.0.0
CATEGORIES=	wip net parallel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-openmpi

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	MPI for Python - Python bindings for MPI
WWW=		https://bitbucket.org/mpi4py/mpi4py/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS?=	libmpi.so:net/openmpi

USE_GITHUB=	yes

USES=		python:3.6+
USE_PYTHON=	distutils
NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

PYDISTUTILS_PKGNAME=${PKGNAME}

# SUB_FILES not working.  Does it not happen before build?
post-patch:
	${CP} ${FILESDIR}/mpi.cfg.in ${WRKSRC}/mpi.cfg
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/mpi.cfg

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/docs ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${COPYTREE_SHARE} ${WRKSRC}/examples ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
