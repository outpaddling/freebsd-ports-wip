PORTNAME=	picrust
PORTVERSION=	20151129
CATEGORIES=	wip biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Phylogenetic Investigation of Communities by Reconstruction of Unobserved STates
WWW=		https://picrust.github.io/picrust/

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}biom-format>0:biology/py-biom-format

RUN_DEPENDS=	${PYNUMPY} pycogent>0:biology/pycogent \
		${PYTHON_PKGNAMEPREFIX}biom-format>0:biology/py-biom-format \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py

USE_GITHUB=	yes
GH_ACCOUNT=	picrust
GH_TAGNAME=	2fafafc

USES=		python:3.6+
USE_PYTHON=	distutils

.include <bsd.port.mk>
