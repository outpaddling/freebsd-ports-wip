# $FreeBSD$

PORTNAME=	globus-cli
PORTVERSION=	1.9.0
CATEGORIES=	wip python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command Line Wrapper over the Globus SDK for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	globus

# Crypto also < 2.5.0
# requests<3.0.0,>=2.0.0
# configobj<6.0.0,>=5.0.6
# jmespath==0.9.2
# click<7.0,>=6.6
RUN_DEPENDS=	${PP}cryptography>=1.8.1:security/py-cryptography@${PY_FLAVOR} \
		${PP}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PP}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PP}jmespath>=0.9.2:devel/py-jmespath@${PY_FLAVOR} \
		${PP}click>=6.6:devel/py-click@${PY_FLAVOR} \
		${PP}globus-sdk-python==1.6.1:wip/py-globus-sdk@${PY_FLAVOR}

PP=	${PYTHON_PKGNAMEPREFIX}

.include <bsd.port.mk>
