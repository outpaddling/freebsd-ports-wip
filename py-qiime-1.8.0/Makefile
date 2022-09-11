PORTNAME=	qiime
PORTVERSION=	1.8.0
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
CATEGORIES=	wip biology
MASTER_SITES=	http://github.com/biocore/qiime/archive/ \
		http://www.drive5.com/uclust/
DISTNAME=	${PORTVERSION}
#DISTFILES=	${PORTVERSION}${EXTRACT_SUFX} \
#		uclustq1.2.22_i86linux32
DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=	${PORTVERSION}${EXTRACT_SUFX}
MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quantitative Insights Into Microbial Ecology
WWW=		https://port.home.page/

LICENSE=	GPLv2

# uclust is a Linux closed-source binary and required for qiime
# ONLY_FOR_ARCH=	i386 amd64

LIB_DEPENDS+=libgmp.so:math/gmp
LIB_DEPENDS+=libffi.so:devel/libffi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LINUX=	yes	# For uclust closed-source binary
USES=		iconv python:2 shebangfix
USE_PYTHON=	distutils
SHEBANG_FILES=	scripts/ec2Clean scripts/ec2Dispatch

PYDISTUTILS_PKGNAME=	qiime

# Add license notification for uclust/usearch

#####################
# Base installation
# http://qiime.org/install/install.html
# Canopy Express
#    Python 2.7.3, numpy 1.5.1 - 1.7.1, MatPlotLib 1.1.0 - 1.3.1
# Other
#    pycogent 1.5.3, biom-format 1.3.1, qcli 0.1.0, pynast 1.2.2, emperor 0.9.3
#    
# Non-python
#    uclust 1.2.22q, fasttree 2.1.3

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.5.1:math/py-numpy \
		${PKGNAMEPREFIX}matplotlib>=1.1.0:math/py-matplotlib \
		pycogent>=1.1.0:biology/pycogent \
		${PKGNAMEPREFIX}biom-format==1.3.1:wip/py-biom-format131 \
		${PKGNAMEPREFIX}qcli>=0.1.0:wip/py-qcli \
		${PKGNAMEPREFIX}pyqi>=0.3.2:wip/py-pyqi \
		${PKGNAMEPREFIX}pynast>=1.2.2:wip/py-pynast \
		${PKGNAMEPREFIX}emperor>=0.9.3:wip/py-emperor \
		${PKGNAMEPREFIX}h5py>=2.3.0:science/py-h5py \
		FastTree>=2.1.7:biology/fasttree \
		muscle>=3.8.31:biology/muscle \
		infernal>=1.0.2:wip/infernal102 \
		rdp-classifier=2.2:wip/rdp-classifier-2.2 \
		microbiomeutil>=r20110519:wip/microbiomeutil \
		cdbfasta>=2010.07.22:biology/cdbfasta
RUN_DEPENDS=	${BUILD_DEPENDS} \
		ncbi-toolkit>=2012.06.20:biology/ncbi-toolkit \
		cd-hit>=4.6.1:biology/cd-hit \
		vsearch:wip/vsearch
BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx

# Hack to work around matplotlib package not installing pyparsing on 10.0
# RUN_DEPENDS+=	${PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing

###############
# Full install

#     jre1.6.0_05 (src_jre) (license: GPL2)
#     rdp_classifier-2.2 (src_rdp) See RDP install notes. (license: GPL)
#     tax2tree 1.0.0 (src_tax2tree)
#     blast-2.2.22 (legacy BLAST from NCBI, NOT BLAST+) (OS X or linux 32-bit) (license: GNU)
#     cd-hit 3.1.1 (src_cdhit) (license: Free access)
#     ChimeraSlayer (via microbiomeutil_2010-04-29) (src_chimeraslayer) See ChimeraSlayer install notes.
#     mothur 1.25.0 (src_mothur) (license: GPL)
#     clearcut v1.0.9 (src_clearcut)
#     raxml 7.3.0 (src_raxml)
#     infernal 1.0.2 (src_infernal) (license: GPL)
#     cdbtools (src_cdbtools)
#     muscle 3.8.31 (src_muscle) (Public domain)
#     rtax 0.984 (src_rtax) (license: BSD)
#     pplacer 1.1 (src_pplacer) (license: GPL)
#     ParsInsert 1.04 (src_parsinsert) (license: GPL)
#     usearch v5.2.236 and/or usearch v6.1 (src_usearch) (license: see http://www.drive5.com/usearch/nonprofit_form.html) At this stage two different versions of usearch are supported. usearch v5.2.236 is referred to as usearch in QIIME, and usearch v6.1 is referred to as usearch61.
# 
# Processing sff files:
# 
#     sfffile and sffinfo (optional, QIIME 1.2.0 and later contain built-in tools for processing sff files although they are about 10x slower than the tools from Roche) (license: proprietary - must be obtained from Roche/454)
# 
# Denoising 454 data:
# 
#     GNU Science Library (required by AmpliconNoise) (src_gsl)
#     AmpliconNoise 1.27 (src_ampliconnoise) See AmpliconNoise install notes.
#     ghc 6.8 (required by the QIIME denoiser) (src_ghc)
# 
# Visualization and plotting steps:
# 
#     cytoscape v2.7.0 (src_cytoscape) (license: LGPL)
# 
# Supervised learning (supervised_learning.py) and compare_categories.py:
# 
#     R 3.0.2 (src_r) See R install notes. (license: GPL2)
# 
# If you plan to build the QIIME documentation locally:
# 
#     Sphinx 1.0.4 (src) See Building the QIIME documentation (license: BSD)
# 
# If you plan to use remote mapping files (stored as Google Spreadsheets) with QIIME (see the tutorial here):
# 
#     gdata 2.0.17 (src) (license: Apache 2.0)
# 
# If you plan to use SourceTracker with QIIME:
# 
#     SourceTracker 0.9.5 (src) (license: GPL)
# 

BUILD_DEPENDS+=	ghc:lang/ghc

# start_parallel_jobs.py is for multithreaded?
post-patch:
	${REINPLACE_CMD} \
		-e 's|qiime_scripts_dir|& ${PREFIX}/bin|g' \
		-e 's|cluster_jobs_fp|& ${PREFIX}/bin/start_parallel_jobs.py|g' \
		${WRKSRC}/qiime/support_files/qiime_config

#post-install:
#	${INSTALL_PROGRAM} ${DISTDIR}/uclustq1.2.22_i86linux32 \
#		${STAGEDIR}${PREFIX}/bin/uclust

.include <bsd.port.mk>
