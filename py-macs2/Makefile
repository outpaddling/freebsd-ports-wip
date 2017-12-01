# $FreeBSD$

PORTNAME=	macs2
PORTVERSION=	2017.05.05
CATEGORIES=	wip biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Novel algorithm for identifying transcript factor binding sites

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.2:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	cython distutils

USE_GITHUB=	yes
GH_ACCOUNT=	taoliu
GH_PROJECT=	MACS
GH_TAGNAME=	6946b2f6571cd0a7cfbb882c79aaa25a05a5c48d

post-patch:
	${MV} -f ${WRKSRC}/setup_w_cython.py ${WRKSRC}/setup.py

post-stage:
	${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*/*.so

.include <bsd.port.mk>
