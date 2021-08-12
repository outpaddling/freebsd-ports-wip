PORTNAME=	ont-fast5-api
DISTVERSION=	3.3.0
CATEGORIES=	wip python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simple interface to HDF5 files of the Oxford Nanopore .fast5 file format

LICENSE=	MPL20
#LICENSE_FILE=	

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.2.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}progressbar>0:misc/py-progressbar

USES=		python
USE_PYTHON=	autoplist distutils

pre-configure:
	@${REINPLACE_CMD} -e 's|progressbar33|progressbar|g' \
		${WRKSRC}/PKG-INFO \
		${WRKSRC}/README.rst \
		${WRKSRC}/setup.py \
		${WRKSRC}/ont_fast5_api.egg-info/PKG-INFO \
		${WRKSRC}/ont_fast5_api.egg-info/requires.txt \
		${WRKSRC}/ont_fast5_api/conversion_tools/conversion_utils.py

.include <bsd.port.mk>
