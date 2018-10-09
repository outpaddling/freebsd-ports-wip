# $FreeBSD$

PORTNAME=	Gemtools
#DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	wip python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C API and a Python module to support and simplify usage of the GEM Mapper

# Check
LICENSE=	GPLv2

USES=		compiler:openmp gmake python
#USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

post-patch:
	${RM} ${WRKSRC}/distribute_setup.py

.include <bsd.port.mk>
