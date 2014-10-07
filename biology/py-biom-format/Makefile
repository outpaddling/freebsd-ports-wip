# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	biom
PORTVERSION=	2.1
# Version 1.3.1 is specifically listed as a dep for qiime
# PORTVERSION=	1.3.1
CATEGORIES=	biology
#MASTER_SITES=	http://github.com/biocore/biom-format/archive/
MASTER_SITES=	http://pypi.python.org/packages/source/b/biom-format/
PKGNAMESUFFIX=	format
DISTNAME=	${PORTNAME}-${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	The Biological Observation Matrix (BIOM) Format Project

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

WRKSRC=		${WRKDIR}/${PORTNAME}-${PKGNAMESUFFIX}-${PORTVERSION}

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	biom

.include <bsd.port.mk>
