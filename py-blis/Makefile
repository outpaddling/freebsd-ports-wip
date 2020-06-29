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

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	32-bit support is deprecated

BUILD_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist distutils

CONFIGURE_ENV=	BLIS_COMPILER=${CC}
MAKE_ENV=	BLIS_COMPILER=${CC}

.include <bsd.port.mk>
