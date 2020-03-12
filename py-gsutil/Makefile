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

USES=		python shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	gslib/vendored/boto/boto/pyami/launch_ami.py \
		gslib/vendored/boto/boto/services/bs.py \
		gslib/vendored/boto/tests/test.py \
		gslib/vendored/boto/tests/fps/test.py

.include <bsd.port.mk>
