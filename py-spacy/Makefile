# $FreeBSD$

PORTNAME=		spacy
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.0
DISTVERSIONSUFFIX=	a4
CATEGORIES=		wip textproc python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Industrial-strength Natural Language Processing (NLP)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cymem>=2.0.0:wip/py-cymem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}preshed>=2.0.0:wip/py-preshed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}murmurhash>=1.0.1:wip/py-murmurhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thinc>=6.12.1:wip/py-thinc@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython distutils
USE_GITHUB=	yes

GH_ACCOUNT=	explosion
GH_PROJECT=	spaCy

.include <bsd.port.mk>
