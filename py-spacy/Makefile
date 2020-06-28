# $FreeBSD$

PORTNAME=		spacy
DISTVERSIONPREFIX=	v
DISTVERSION=		2.3.0
CATEGORIES=		wip textproc python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Industrial-strength Natural Language Processing (NLP)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.24.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}murmurhash>=0.28.0:devel/py-murmurhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cymem>=2.0.2:devel/py-cymem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}preshed>=3.0.2:devel/py-preshed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thinc>=7.4.1:wip/py-thinc@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.24.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}murmurhash>=0.28.0:devel/py-murmurhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cymem>=2.0.2:devel/py-cymem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}preshed>=3.0.2:devel/py-preshed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thinc>=7.4.1:wip/py-thinc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cython-blis>=0.4.0:wip/py-blis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wasabi>=0.4.0:wip/py-wasabi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}srsly>=1.0.2:wip/py-srsly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}catalogue>=0.0.7:wip/py-catalogue@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.38:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plac>=0.9.6:devel/py-plac@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathlib==1.0.1:wip/py-pathlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cytoolz>=0:devel/py-cytoolz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython distutils
USE_GITHUB=	yes

GH_ACCOUNT=	explosion
GH_PROJECT=	spaCy

post-patch:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' ${WRKSRC}/bin/spacy

.include <bsd.port.mk>
