PORTNAME=	dna-features-viewer
DISTVERSION=	3.1.5
CATEGORIES=	wip biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dna_features_viewer-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python library to visualize DNA features, e.g. GenBank or Gff files
WWW=		https://github.com/Edinburgh-Genome-Foundry/DnaFeaturesViewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcbio-gff>0:biology/py-bcbio-gff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
