PORTNAME=	pyjwt
PORTVERSION=	1.6.4
CATEGORIES=	wip www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyJWT-${PORTVERSION}

MAINTAINER=	terje@elde.net
COMMENT=	JSON Web Token implementation in Python
WWW=		https://github.com/progrium/pyjwt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Some tests are skipped without pycrypto, but its not
# referenced as a requirement anymore.
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

OPTIONS_DEFINE=	RSASSA

RSASSA_DESC=		RSASSA-PKCS1 v1.5 signature support
RSASSA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -c /dev/null -v -rs

.include <bsd.port.mk>
