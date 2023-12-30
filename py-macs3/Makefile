PORTNAME=		MACS3
DISTVERSIONPREFIX=	v
DISTVERSION=		3.0.0
CATEGORIES=		wip biology python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Peak caller aimed at transcription factor binding sites
WWW=		https://github.com/taoliu/MACS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cython3>0:lang/cython3@${PY_FLAVOR} \
		${PYNUMPY} \
		simde>0:devel/simde \
		${PYTHON_PKGNAMEPREFIX}cykhash>0:devel/py-cykhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hmmlearn>0:math/py-hmmlearn@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cykhash>0:devel/py-cykhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hmmlearn>0:math/py-hmmlearn@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		bash:shells/bash

USES=		localbase python shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent pep517

GH_ACCOUNT=	macs3-project
GH_PROJECT=	MACS
SHEBANG_FILES=	test/cmdlinetest* test/prockreport test/*.py test/pyprofile*

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/MACS3/*/*.so

do-test: install
	@cd ${WRKSRC}/test && ./cmdlinetest tag

.include <bsd.port.mk>
