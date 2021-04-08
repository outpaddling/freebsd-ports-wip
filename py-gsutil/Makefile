# Note: Maybe should be installed as part of google-cloud-sdk
PORTNAME=	gsutil
DISTVERSION=	4.48
CATEGORIES=	wip sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line access to Google Cloud Storage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# Deps from setup.py
#    'gcs-oauth2-boto-plugin>=2.5',
#    'google-apitools>=0.5.30',
#    'google-reauth>=0.1.0',
#    # TODO: Sync submodule with tag referenced here once #339 is fixed in mock.
#    'mock==2.0.0',
#    'retry_decorator>=1.0.0',
#    # Not using 1.02 because of:
#    #   https://code.google.com/p/socksipy-branch/issues/detail?id=3
#    'SocksiPy-branch==1.01',
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.9.4:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod>=1.7:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.14.1:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.11.3:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monotonic>=1.4:devel/py-monotonic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=4.1.3:security/py-oauth2client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	gslib/vendored/boto/boto/pyami/launch_ami.py \
		gslib/vendored/boto/boto/services/bs.py \
		gslib/vendored/boto/tests/test.py \
		gslib/vendored/boto/tests/fps/test.py

.include <bsd.port.mk>
