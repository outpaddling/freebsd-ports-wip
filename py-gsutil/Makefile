# $FreeBSD$

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
#    'argcomplete>=1.9.4',
#    'crcmod>=1.7',
#    'fasteners>=0.14.1',
#    'gcs-oauth2-boto-plugin>=2.5',
#    'google-apitools>=0.5.30',
#    'httplib2>=0.11.3',
#    'google-reauth>=0.1.0',
#    # TODO: Sync submodule with tag referenced here once #339 is fixed in mock.
#    'mock==2.0.0',
#    'monotonic>=1.4',
#    'oauth2client==4.1.3',
#    'pyOpenSSL>=0.13',
#    'retry_decorator>=1.0.0',
#    'six>=1.12.0',
#    # Not using 1.02 because of:
#    #   https://code.google.com/p/socksipy-branch/issues/detail?id=3
#    'SocksiPy-branch==1.01',

USES=		python shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	gslib/vendored/boto/boto/pyami/launch_ami.py \
		gslib/vendored/boto/boto/services/bs.py \
		gslib/vendored/boto/tests/test.py \
		gslib/vendored/boto/tests/fps/test.py

.include <bsd.port.mk>
