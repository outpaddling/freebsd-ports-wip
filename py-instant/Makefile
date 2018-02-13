# Remove per Li-Wen's permission: Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD: head/devel/py-instant/Makefile 460452 2018-01-31 01:07:07Z jwb $

PORTNAME=	instant
# Caution: Must use version compatible with other FEniCS project ports
DISTVERSION=	2017.2.0
CATEGORIES=	wip devel python
MASTER_SITES=	https://bitbucket.org/fenics-project/instant/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python module for instant inlining of C and C++ code in Python

LICENSE=	LGPL3

RUN_DEPENDS=	swig3.0:devel/swig30

USES=			python
USE_PYTHON=		autoplist distutils

.include <bsd.port.mk>
