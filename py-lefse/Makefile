# $FreeBSD$

PORTNAME=	lefse
DISTVERSION=	1.0.8
CATEGORIES=	wip python
MASTER_SITES=	https://bitbucket.org/nsegata/lefse/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Linear discriminant analysis effect size

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

# R libraries: splines, stats4, survival, mvtnorm, modeltools, coin, MASS
RUN_DEPENDS=	${PYNUMPY} \
		${PKGNAMEPREFIX}matplotlib>=1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PKGNAMEPREFIX}rpy2>=2.1:math/py-rpy2@${PY_FLAVOR} \
		${PKGNAMEPREFIX}argparse>=0:devel/py-argparse@${PY_FLAVOR} \
		R-cran-mvtnorm>0:math/R-cran-mvtnorm

USES=		python:3.6+ shebangfix tar:bz2

SHEBANG_FILES=	${WRKSRC}/*.py ${WRKSRC}/lefsebiom/*.py

WRKSRC=		${WRKDIR}/nsegata-lefse-3ce86f78d59e
NO_BUILD=	yes
NO_ARCH=	yes

pre-configure:
	@${CP} ${WRKSRC}/lefse.py ${WRKSRC}/lefse.py.orig
	@${PRINTF} "#!${PYTHON_CMD}\n\n" > ${WRKSRC}/lefse.py
	@${CAT} ${WRKSRC}/lefse.py.orig >> ${WRKSRC}/lefse.py
	@${REINPLACE_CMD} -e 's|	|        |g' ${WRKSRC}/*.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lefsebiom ${STAGEDIR}${PYTHON_SITELIBDIR})
	${RM} ${STAGEDIR}${PREFIX}/bin/__init__.py ${STAGEDIR}${PYTHON_SITELIBDIR}/lefsebiom/__init__.py

.include <bsd.port.mk>
