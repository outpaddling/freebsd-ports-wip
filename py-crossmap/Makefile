# $FreeBSD$

PORTNAME=	crossmap
DISTVERSION=	0.5.2
CATEGORIES=	wip python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CrossMap-${DISTVERSION}

MAINTAINER=	bacon@moray.acadix.biz
COMMENT=	Lift over genomics coordinates between assemblies

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyBigWig>0:wip/py-bigwig@${PY_FLAVOR}

# CrossMap conflicts with its own dependency
#		${PYTHON_PKGNAMEPREFIX}bx-python>0:biology/py-bx-python@${PY_FLAVOR} \

USES=		python:3.5+
USE_PYTHON=	autoplist cython distutils

.include <bsd.port.mk>
