# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	illumina-utils
PORTVERSION=	1.4.4
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Tools for Illumina paired-end data (for CASAVA 1.7+ pipeline)

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:${PORTSDIR}/devel/py-pip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}levenshtein>0:${PORTSDIR}/devel/py-levenshtein

USES=		python
USE_PYTHON=	distutils

.include <bsd.port.mk>
