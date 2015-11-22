# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	pbcore
# pbh5tools does not work with latest pbcore release, 1.2.x
# https://github.com/PacificBiosciences/cDNA_primer/issues/11#issuecomment-133767711
PORTVERSION=	0.9.1
CATEGORIES=	biology
MASTER_SITES=	http://github.com/PacificBiosciences/pbcore/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Python modules for building PacBio bioinformatics applications

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.7.1:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.0.1:${PORTSDIR}/science/py-h5py \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.8.1:/usr/wip/biology/py-pysam
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.7.1:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.0.1:${PORTSDIR}/science/py-h5py \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.8.1:/usr/wip/biology/py-pysam

USES=		python
USE_PYTHON=	distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
