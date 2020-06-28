# $FreeBSD$

PORTNAME=		thinc
DISTVERSIONPREFIX=	v
DISTVERSION=		7.4.1
CATEGORIES=		wip devel python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	SpaCy's Machine Learning library for NLP in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython-blis>=0.4.0:wip/py-blis@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	explosion

.include <bsd.port.mk>
