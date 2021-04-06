
PORTNAME=	pbcore
# pbh5tools does not work with latest pbcore release, 1.2.x
# https://github.com/PacificBiosciences/cDNA_primer/issues/11#issuecomment-133767711
PORTVERSION=	0.9.1
CATEGORIES=	wip biology
MASTER_SITES=	http://github.com/PacificBiosciences/pbcore/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python modules for building PacBio bioinformatics applications

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	cython:lang/cython \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.7.1:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.0.1:science/py-h5py \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.8.1:wip/py-pysam
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.7.1:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.0.1:science/py-h5py \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.8.1:wip/py-pysam

USES=		python:3.6+
USE_PYTHON=	distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
