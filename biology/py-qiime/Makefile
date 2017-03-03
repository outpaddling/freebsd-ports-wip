# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	qiime
PORTVERSION=	1.9.1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
CATEGORIES=	biology
MASTER_SITES=	http://github.com/biocore/qiime/archive/ \
		http://www.drive5.com/uclust/
DISTNAME=	${PORTVERSION}
#DISTFILES=	${PORTVERSION}${EXTRACT_SUFX} \
#		uclustq1.2.22_i86linux32
DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=	${PORTVERSION}${EXTRACT_SUFX}
MAINTAINER=	bacon4000@gmail.com
COMMENT=	Quantitative Insights Into Microbial Ecology

LICENSE=	GPLv2

# Base install
#

# http://qiime.org/install/alternative.html
# Alignment, tree-building, taxonomy assignment, OTU picking, and other data generation steps:
# 
#     jre1.6.0_05
#     rdp_classifier-2.2
#     blast-2.2.22
#     cd-hit 3.1.1
#     ChimeraSlayer
#     mothur 1.25.0
#     clearcut v1.0.9
#     raxml 7.3.0
#     infernal 1.0.2
#     cdbtools
#     muscle 3.8.31
#     rtax 0.984
#     usearch v5.2.236 and/or usearch v6.1 (src_usearch) (license: see http://www.drive5.com/usearch/nonprofit_form.html) At this stage two different versions of usearch are supported. usearch v5.2.236 is referred to as usearch in QIIME, and usearch v6.1 is referred to as usearch61.
#     sumaclust v1.0.00
#     swarm 1.2.19
#     sortmerna 2.0
# 
# Processing sff files:
# 
#     sfffile and sffinfo (optional, QIIME 1.2.0 and later contain built-in tools for processing sff files although they are about 10x slower than the tools from Roche) (license: proprietary - must be obtained from Roche/454)
# 
# Denoising 454 data:
# 
#     GNU Science Library (required by AmpliconNoise)
#     AmpliconNoise 1.27
#     ghc 6.8 (required by the QIIME denoiser)
# 
# Network visualization:
# 
#     cytoscape v2.7.0
# 
# Advanced statistics, including those performed in supervised_learning.py, detrend.py and compare_categories.py:
# 
#     R 3.1.2
# 
# If you plan to use SourceTracker with QIIME:
# 
#     SourceTracker 0.9.5
# 
# For joining paired end reads, with join_paired_ends.py and multiple_join_paired_ends.py:
# 
#     ea-utils 1.1.2-537
#     SeqPrep v1.1
# 
# For improved performance with large BIOM files, or if you’re working with BIOM format 2.x files
# 
#     HDF5
#     h5py
 
LIB_DEPENDS+=libgmp.so:math/gmp
LIB_DEPENDS+=libffi.so:devel/libffi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LINUX=	yes	# For uclust closed-source binary
USES=		iconv python:2
USE_PYTHON=	distutils

PYDISTUTILS_PKGNAME=	qiime

# FIXME: Many of these are probably just run depends
BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.9.0:math/py-numpy \
		${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy \
		${PKGNAMEPREFIX}matplotlib:math/py-matplotlib \
		pycogent:biology/pycogent \
		${PKGNAMEPREFIX}natsort:devel/py-natsort \
		${PKGNAMEPREFIX}biom-format==1.3.1:/usr/wip/biology/py-biom-format131 \
		${PKGNAMEPREFIX}qcli>=0.1.0:/usr/wip/biology/py-qcli \
		${PKGNAMEPREFIX}pyqi>=0.3.2:/usr/wip/biology/py-pyqi \
		${PKGNAMEPREFIX}pynast>=1.2.2:/usr/wip/biology/py-pynast \
		${PKGNAMEPREFIX}emperor>=0.9.3:/usr/wip/biology/py-emperor \
		${PKGNAMEPREFIX}h5py>=2.3.0:science/py-h5py \
		FastTree>=2.1.7:biology/fasttree \
		muscle>=3.8.31:biology/muscle \
		infernal>=1.0.2:/usr/wip/biology/infernal102 \
		rdp-classifier=2.2:/usr/wip/biology/rdp-classifier-2.2 \
		microbiomeutil>=r20110519:/usr/wip/biology/microbiomeutil \
		cdbfasta>=2010.07.22:biology/cdbfasta \
		sphinx-build:textproc/py-sphinx \
		ghc:lang/ghc
RUN_DEPENDS=	${BUILD_DEPENDS} \
		ncbi-toolkit>=2012.06.20:biology/ncbi-toolkit \
		cd-hit>=4.6.1:biology/cd-hit \
		usearch6.1.544_i86linux32:/usr/wip/biology/linux-usearch-6.1

# Can we substitute vsearch for usearch?
# Make this an OPTION?
#		vsearch:/usr/wip/biology/vsearch

# start_parallel_jobs.py is for multithreaded?
post-patch:
	${REINPLACE_CMD} \
		-e 's|qiime_scripts_dir|& ${PREFIX}/bin|g' \
		-e 's|cluster_jobs_fp|& ${PREFIX}/bin/start_parallel_jobs.py|g' \
		${WRKSRC}/qiime/support_files/qiime_config

.include <bsd.port.mk>
