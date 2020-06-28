# $FreeBSD$

PORTNAME=	blis
DISTVERSION=	0.4.1
CATEGORIES=	wip math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast matrix-multiplication as a self-contained Python library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist distutils

CONFIGURE_ENV=	BLIS_COMPILER=${CC}
MAKE_ENV=	BLIS_COMPILER=${CC}

.include <bsd.port.mk>
