# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	biom
PORTVERSION=	2.0.1
CATEGORIES=	biology science
MASTER_SITES=	https://github.com/biocore/biom-format/archive/
PKGNAMESUFFIX=	format
DISTNAME=	${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	The Biological Observation Matrix (BIOM) Format Project

USE_PYTHON=             yes
USE_PYDISTUTILS=        yes
PYDISTUTILS_PKGNAME=    biom

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

.include <bsd.port.mk>
