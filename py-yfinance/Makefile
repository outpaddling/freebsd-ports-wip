PORTNAME=	yfinance
DISTVERSION=	0.1.54
CATEGORIES=	wip python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Yahoo! Finance market data downloader
WWW=		https://pypi.python.org/pypi/yfinance

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.24:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas-datareader>=0.4.0:math/py-pandas-datareader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multitasking>=0.0.7:wip/py-multitasking@${PY_FLAVOR} \
		${NUMPY}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
