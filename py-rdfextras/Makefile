PORTNAME=	rdfextras
PORTVERSION=	0.4
CATEGORIES=	wip python
MASTER_SITES=	https://github.com/RDFLib/rdfextras/archive/
MASTER_SITE_SUBDIR=${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=
WWW=		https://pypi.python.org/pypi/rdf-extras

USES=		python:3.6+
USE_PYTHON=	distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}rdflib==3.4.0:wip/py-rdflib340

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
