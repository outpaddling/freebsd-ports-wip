# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	rdfextras
PORTVERSION=	0.4
CATEGORIES=	wip python
MASTER_SITES=	https://github.com/RDFLib/rdfextras/archive/
MASTER_SITE_SUBDIR=${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=

USES=		python
USE_PYTHON=	distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}rdflib==3.4.0:wip/py-rdflib340

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
