PORTNAME=	pywgsim
DISTVERSION=	0.6.0
CATEGORIES=	wip biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Modified wgsim genomic data simulator
WWW=		https://pypi.python.org/pypi/pywgsim

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plac>=0:devel/py-plac@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pywgsim/*.so

.include <bsd.port.mk>
