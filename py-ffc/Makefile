# $FreeBSD$

PORTNAME=	ffc
# Caution: Must use version compatible with other FEniCS project ports
DISTVERSION=	2017.2.0
CATEGORIES=	wip math python
MASTER_SITES=	https://bitbucket.org/fenics-project/ffc/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Compiler for finite element variational forms

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ufl>0:wip/py-ufl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fiat>0:wip/py-fiat@${FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
