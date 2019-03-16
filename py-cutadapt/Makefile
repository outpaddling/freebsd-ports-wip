# $FreeBSD: head/biology/py-cutadapt/Makefile 480173 2018-09-20 14:10:52Z jwb $

PORTNAME=	cutadapt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	wip biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trim adapters from high-throughput sequencing reads

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xopen>=0.3.2:archivers/py-xopen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bz2file>=0.98:archivers/py-bz2file@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	marcelm

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cutadapt/*.so

.include <bsd.port.mk>
