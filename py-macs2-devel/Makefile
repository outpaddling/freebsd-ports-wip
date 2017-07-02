# Created by: Charlie %%FULLNAME%% <root@freebsd-10.1.local>
# $FreeBSD$

PORTNAME=	MACS
PORTVERSION=	2017.05.05
CATEGORIES=	wip biology
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Novel algorithm for identifying transcript factor binding sites

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy \
		cython:lang/cython

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	macs2

USE_GITHUB=	yes
GH_ACCOUNT=	taoliu
GH_TAGNAME=	6946b2f6571cd0a7cfbb882c79aaa25a05a5c48d

post-patch:
	${MV} -f ${WRKSRC}/setup_w_cython.py ${WRKSRC}/setup.py

post-stage:
	${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*/*.so

.include <bsd.port.mk>
