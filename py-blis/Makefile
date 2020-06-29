# $FreeBSD$

PORTNAME=	blis
DISTVERSION=	0.4.1
CATEGORIES=	wip math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast BLAS-like operations from Python and Cython, without the tears

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	32-bit support is deprecated

BUILD_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist cython distutils

CONFIGURE_ENV=	BLIS_COMPILER=${CC} BLIS_ARCH="generic"
MAKE_ENV=	BLIS_COMPILER=${CC} BLIS_ARCH="generic"

.include <bsd.port.mk>
