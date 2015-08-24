# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	rdfextras
PORTVERSION=	0.4
CATEGORIES=	python
MASTER_SITES=	https://github.com/RDFLib/rdfextras/archive/
MASTER_SITE_SUBDIR=${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}rdflib==3.4.0:/usr/wip/textproc/py-rdflib340

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
