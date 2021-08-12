PORTNAME=	ont-fast5-api
DISTVERSIONPREFIX=	release_
DISTVERSION=	4.0.0
CATEGORIES=	wip python
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
USE_GITHUB=	yes

GH_ACCOUNT=	nanoporetech
GH_PROJECT=	ont_fast5_api

#TEST_WRKSRC=	${WRKSRC}/py_ont_

post-patch:
	${RM} ${WRKSRC}/ont_fast5_api/vbz_plugin/*

pre-configure:
	@${REINPLACE_CMD} -e 's|progressbar33|progressbar|g' \
		${WRKSRC}/setup.py \
		${WRKSRC}/README.rst \
		${WRKSRC}/ont_fast5_api/conversion_tools/conversion_utils.py

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
