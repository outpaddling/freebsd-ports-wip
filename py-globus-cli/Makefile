PORTNAME=	globus-cli
PORTVERSION=	1.12.0
CATEGORIES=	wip python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command Line Wrapper over the Globus SDK for Python
WWW=		https://github.com/globus/globus-cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	globus

RUN_DEPENDS=	${PP}cryptography>=1.8.1:security/py-cryptography@${PY_FLAVOR} \
		${PP}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PP}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PP}jmespath>=0.9.2:devel/py-jmespath@${PY_FLAVOR} \
		${PP}click>=7.1.1:wip/py-click@${PY_FLAVOR} \
		${PP}globus-sdk-python==1.9.0:wip/py-globus-sdk@${PY_FLAVOR}

NO_ARCH=	yes

PP=	${PYTHON_PKGNAMEPREFIX}

.include <bsd.port.mk>
