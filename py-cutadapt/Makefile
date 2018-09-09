# $FreeBSD: head/biology/py-cutadapt/Makefile 472884 2018-06-20 17:05:41Z mat $

PORTNAME=	cutadapt
PORTVERSION=	1.18
CATEGORIES=	wip biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Finds and removes adapter sequences, primers, poly-A tails, etc

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xopen>0:archivers/py-xopen@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cutadapt/*.so

.include <bsd.port.mk>
