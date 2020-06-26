# $FreeBSD$

PORTNAME=		cython-blis
DISTVERSIONPREFIX=	v
DISTVERSION=		0.4.1
CATEGORIES=		wip math python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast matrix-multiplication as a self-contained Python library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	explosion

CONFIGURE_ENV=	BLIS_COMPILER=${CC}
MAKE_ENV=	BLIS_COMPILER=${CC}

.include <bsd.port.mk>
