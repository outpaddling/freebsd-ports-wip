PORTNAME=	klustaviewa
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=      v
CATEGORIES=	wip python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GUI for spike sorting manual stage in Python
WWW=		https://github.com/klusta-team/klustaviewa

LICENSE=	BSD3CLAUSE

# Should be klustakwik==${PORTVERSION}, but klustkwik is on 0.3.0.rc2
# at the moment, which is an illegal version.
RUN_DEPENDS=	KlustaKwik:wip/klustakwik \
		${PYTHON_PKGNAMEPREFIX}qtools>=0:wip/py-qtools \
		${PYTHON_PKGNAMEPREFIX}kwiklib==${PORTVERSION}:wip/py-kwiklib \
		${PYTHON_PKGNAMEPREFIX}spikedetekt==${PORTVERSION}:wip/py-spikedetekt

USES=		python:3.6+
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	klusta-team

.include <bsd.port.mk>
