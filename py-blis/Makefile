PORTNAME=	blis
DISTVERSION=	0.4.1
CATEGORIES=	wip math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast BLAS-like operations from Python and Cython, without the tears
WWW=		https://github.com/explosion/cython-blis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Works on i386 with BLIS_ARCH=generic
# NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
# NOT_FOR_ARCHS_REASON=	32-bit support is deprecated

BUILD_DEPENDS=	${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	autoplist cython distutils

# BLIS_ARCH defaults to x86_64, which has hard-coded -mavx2, etc.
CONFIGURE_ENV=	BLIS_COMPILER=${CC} BLIS_ARCH="generic"
MAKE_ENV=	BLIS_COMPILER=${CC} BLIS_ARCH="generic"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/blis/*.so

.include <bsd.port.mk>
