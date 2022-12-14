PORTNAME=	instant
# Caution: Must use version compatible with other FEniCS project ports
DISTVERSION=	2017.2.0
CATEGORIES=	wip devel python
MASTER_SITES=	https://bitbucket.org/fenics-project/instant/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python module for instant inlining of C and C++ code in Python
WWW=		https://fenicsproject.org/

LICENSE=	LGPL3

RUN_DEPENDS=	swig3.0:devel/swig30

USES=			python:3.6+
USE_PYTHON=		autoplist distutils

.include <bsd.port.mk>
