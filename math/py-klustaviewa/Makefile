# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	klustaviewa
PORTVERSION=	0.3.0
CATEGORIES=	python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	GUI for spike sorting manual stage in Python

LICENSE=	BSD3CLAUSE

# Should be klustakwik==${PORTVERSION}, but klustkwik is on 0.3.0.rc2
# at the moment, which is an illegal version.
RUN_DEPENDS=	KlustaKwik:/usr/wip/math/klustakwik \
		${PYTHON_PKGNAMEPREFIX}qtools>=0:/usr/wip/graphics/py-qtools \
		${PYTHON_PKGNAMEPREFIX}kwiklib==${PORTVERSION}:/usr/wip/math/py-kwiklib \
		${PYTHON_PKGNAMEPREFIX}spikedetekt==${PORTVERSION}:/usr/wip/math/py-spikedetekt

USES=		python
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	klusta-team
GH_TAGNAME=	v${PORTVERSION}

.include <bsd.port.mk>
