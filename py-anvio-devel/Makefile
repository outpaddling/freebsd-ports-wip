PORTNAME=		anvio
DISTVERSIONPREFIX=	v
DISTVERSION=		5.2-14
DISTVERSIONSUFFIX=	-g85b1fd4e
CATEGORIES=		wip python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Analysis and visualization platform for 'omics data
WWW=		https://merenlab.org/software/anvio/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# 3rd-party: http://merenlab.org/2016/06/18/installing-third-party-software/
# Need: modeller
LIB_DEPENDS=	libgsl.so:math/gsl \
		libhdf5.so:science/hdf5
RUN_DEPENDS=	bash:shells/bash \
		samtools>0:biology/samtools \
		hmmer>0:biology/hmmer \
		FastTree>0:biology/fasttree \
		muscle>0:biology/muscle \
		R>0:math/R \
		R-cran-gridExtra>0:graphics/R-cran-gridExtra \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-gtools>0:devel/R-cran-gtools \
		${PYTHON_PKGNAMEPREFIX}mistune>0:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django>0:www/py-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		Prodigal>0:wip/prodigal \
		centrifuge>0:wip/centrifuge \
		mcl>0:wip/mcl \
		xssp>0:wip/xssp \
		FAMSA>0:wip/famsa \
		R-cran-optparse>0:wip/R-cran-optparse \
		${PYTHON_PKGNAMEPREFIX}ete3>0:wip/py-ete3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eggnog-mapper>0:wip/py-eggnog-mapper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake>0:wip/py-snakemake@${PY_FLAVOR}

USES=		python:3.6+ shebangfix sqlite
USE_PYTHON=	autoplist cython distutils
USE_GITHUB=	yes

SHEBANG_FILES=	anvio/workflows/metagenomics/test/*.sh \
		anvio/tests/*.sh \
		anvio/tests/*/*.sh \
		anvio/tests/server/run_server_tests.py \
		sandbox/anvi-script-FASTA-to-contigs-db \
		sandbox/*.sh
GH_ACCOUNT=	merenlab

.include <bsd.port.mk>
