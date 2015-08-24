# Created by: ijliao
# $FreeBSD: head/textproc/py-rdflib/Makefile 374183 2014-12-07 10:01:36Z mva $

PORTNAME=	rdflib
PORTVERSION=	3.4.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for RDF manipulation

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0:${PORTSDIR}/devel/py-isodate \
	${PYTHON_PKGNAMEPREFIX}parsing>=2.0.1:${PORTSDIR}/devel/py-parsing \
	${PYTHON_PKGNAMEPREFIX}sparqlwrapper>=1.5.2:${PORTSDIR}/textproc/py-sparqlwrapper \
	${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib

USES=		python
USE_PYTHON=	distutils

.include <bsd.port.mk>
