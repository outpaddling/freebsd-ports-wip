
PORTNAME=	gemtools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	wip python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C API and a Python module to support usage of the GEM Mapper

# Check
LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=0:devel/py-argparse@${PY_FLAVOR}

USES=		compiler:openmp gmake python:2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils

pre-configure:
	@${RM} ${WRKSRC}/distribute_setup.py
	@${REINPLACE_CMD} -e 's|^inline||' -e 's|^static inline||' \
		${WRKSRC}/GEMTools/src/gt_error.c \
		${WRKSRC}/GEMTools/resources/src/bgzf.c \
		${WRKSRC}/GEMTools/resources/src/json.c \
		${WRKSRC}/GEMTools/include/gt_error.h

.include <bsd.port.mk>
