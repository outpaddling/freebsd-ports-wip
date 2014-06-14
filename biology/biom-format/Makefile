# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	biom
PORTVERSION=	2.0.1
CATEGORIES=	biology science
MASTER_SITES=	http://github.com/biocore/biom-format/archive/
PKGNAMESUFFIX=	format
DISTNAME=	${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	The Biological Observation Matrix (BIOM) Format Project

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

WRKSRC=		${WRKDIR}/${PORTNAME}-${PKGNAMESUFFIX}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	biom

.include <bsd.port.mk>
