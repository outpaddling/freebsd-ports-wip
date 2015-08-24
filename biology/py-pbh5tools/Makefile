# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	pbh5tools
PORTVERSION=	2.3.0p4
CATEGORIES=	biology
MASTER_SITES=	http://github.com/PacificBiosciences/pbh5tools/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	smrtanalysis-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for manipulating HDF5 files produced by Pacific Biosciences

LICENSE=	BSD3CLAUSE

# Using pbcore 0.9.1 as a test due to errors with 1.2.2
# See https://github.com/PacificBiosciences/cDNA_primer/issues/11
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:${PORTSDIR}/devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}avro>=0:${PORTSDIR}/devel/py-avro \
		${PYTHON_PKGNAMEPREFIX}pbcore==0.9.1:/usr/wip/biology/py-pbcore
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:${PORTSDIR}/devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}avro>=0:${PORTSDIR}/devel/py-avro \
		${PYTHON_PKGNAMEPREFIX}pbcore>=0:/usr/wip/biology/py-pbcore

USES=		python
USE_PYTHON=	distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

.include <bsd.port.mk>
