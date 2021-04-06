# TODO:
# Patch setup.py to avoid downloading files during build phase
#     Remaining: sortmerna, suma_package, swarm
# Finish adding deps

PORTNAME=	qiime
PORTVERSION=	1.9.1
CATEGORIES=	wip biology
MASTER_SITES=	http://github.com/biocore/qiime/archive/ \
		http://www.drive5.com/uclust/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DISTFILES=	${PORTVERSION}${EXTRACT_SUFX} \
		uclustq1.2.22_i86linux64
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quantitative Insights Into Microbial Ecology

LICENSE=	GPLv2

#OPTIONS_DEFINE=	VSEARCH
#VSEARCH_DESC=	Use open source vsearch in place of usearch

# FIXME: Many of these are probably just run depends
# FIXME: Remove deps of deps
# From pip install:
# cogent==1.5.3, but 1.9.0 is the next release on Github
# natsort<4.0.0
# scikit-bio<0.3.0,>=0.2.3 (from qiime)
# biom-format<2.2.0,>=2.1.4
# emperor<1.0.0,>=0.9.51
# scikit-bio<0.3.0,>=0.2.3
# burrito-fillings<0.2.0,>=0.1.1
# pandas>=0.13.1
# burrito<1.0.0,>=0.9.1
# qiime-default-reference<0.2.0,>=0.1.2
# python-dateutil
# pytz
# cycler
# pyparsing!=2.0.4,!=2.1.2,>=1.5.6
# click
# future>=0.14.3
# pyqi
# six
# IPython
# pickleshare
# backports.shutil-get-terminal-size
# prompt-toolkit<2.0.0,>=1.0.4
# traitlets>=4.2
# pexpect
# pathlib2
# simplegeneric>0.8
# decorator
# pygments
# wcwidth
# ipython-genutils
# enum34
# ptyprocess>=0.5
# scandir

# setup.py
#      install_requires=['numpy >= 1.9.0',
#                        'scipy >= 0.14.0',
#                        'cogent == 1.5.3',
#                        'natsort < 4.0.0',
#                        'matplotlib >= 1.1.0, != 1.4.2',
#                        'pynast == 1.2.2', 'qcli >= 0.1.1, < 0.2.0', 'gdata',
#                        'biom-format >= 2.1.4, < 2.2.0',
#                        'emperor >= 0.9.51, < 1.0.0',
#                        'scikit-bio >= 0.2.3, < 0.3.0',
#                        'burrito-fillings >= 0.1.1, < 0.2.0',
#                        'pandas >= 0.13.1', 'burrito >= 0.9.1, < 1.0.0',
#                        'qiime-default-reference >= 0.1.2, < 0.2.0'],
#      extras_require={'all': ['ipython[notebook] >= 3.1.0, < 4.0.0',
#                              'sphinx >= 0.3']}

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.9.0:math/py-numpy \
		${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy \
		${PKGNAMEPREFIX}scikit-bio==0.2.3:wip/py-scikit-bio-0.2.3 \
		pycogent>=1.5.3:biology/pycogent \
		${PKGNAMEPREFIX}natsort>0:devel/py-natsort \
		${PKGNAMEPREFIX}matplotlib>=1.1.0:math/py-matplotlib \
		${PKGNAMEPREFIX}pynast==1.2.2:wip/py-pynast \
		${PKGNAMEPREFIX}qcli>=0.1.1:wip/py-qcli \
		${PKGNAMEPREFIX}gdata>=2.0.18:devel/py-gdata \
		${PKGNAMEPREFIX}biom-format>=2.1.4:biology/py-biom-format \
		${PKGNAMEPREFIX}emperor>=0.9.51:wip/py-emperor \
		${PKGNAMEPREFIX}burrito-fillings>=0.1.1:wip/py-burrito-fillings \
		${PKGNAMEPREFIX}pandas>=0.13.1:math/py-pandas \
		${PKGNAMEPREFIX}burrito>=0.9.1:wip/py-burrito \
		${PKGNAMEPREFIX}qiime-default-reference>=0.1.2:wip/py-qiime-default-reference \
		${PKGNAMEPREFIX}ipython>0:devel/ipython \
		${PKGNAMEPREFIX}sphinx>=0.3:textproc/py-sphinx \
		ghc:lang/ghc

# Unbundled
BUILD_DEPENDS+=	FastTree>=2.1.7:biology/fasttree \
		sortmerna==2.0:wip/sortmerna \
		sumaclust>=1.0.00:wip/sumaclust \
		swarm==1.2.19:wip/swarm

# Not listed in setup.py, but installed by pip. Probably pulled in as subdeps.
#		${PKGNAMEPREFIX}dateutil>0:devel/py-dateutil \
#		${PKGNAMEPREFIX}pytz>0:devel/py-pytz \
#		${PKGNAMEPREFIX}cycler>0:devel/py-cycler \
#		${PKGNAMEPREFIX}pyparsing>=1.5.6:devel/py-pyparsing \
#		${PKGNAMEPREFIX}click>0:devel/py-click \
#		${PKGNAMEPREFIX}future>=0.14.3:devel/py-future \
#		${PKGNAMEPREFIX}pyqi>0:devel/py-pyqi \
#		${PKGNAMEPREFIX}six>0:devel/py-six \
#		${PKGNAMEPREFIX}:/usr/wip/ \
#		${PKGNAMEPREFIX}h5py>=2.3.0:science/py-h5py \

LIB_DEPENDS+=libgmp.so:math/gmp
LIB_DEPENDS+=libffi.so:devel/libffi

# Not sure how well vsearch will work with qiime, but it's a free sub for
# uclust/usearch, which only runs on x86 and only the 32-bit version is free.
RUN_DEPENDS=	${BUILD_DEPENDS} \
		ncbi-toolkit>=2012.06.20:biology/ncbi-toolkit \
		cd-hit>=4.6.1:biology/cd-hit \
		vsearch:wip/vsearch

# Not listed as a dep, but tests fail without it
# Newer rdp-classifier may work.  all_tests.py failed with 2.12.
# java.lang.NoClassDefFoundError: org/apache/commons/cli/...
RUN_DEPENDS+=	muscle>=3.8.31:biology/muscle \
		rdp-classifier22==2.2:wip/rdp-classifier-2.2 \
		infernal==1.0.2:wip/infernal102 \
		rtax:wip/rtax \
		mothur:wip/mothur \
		blat>0:biology/blat \
		fastq-join>0:wip/fastq-join \
		R-cran-ape>0:wip/R-cran-ape \
		R-cran-optparse>0:wip/R-cran-optparse \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		R-cran-randomForest>0:devel/R-cran-randomForest \
		R-cran-vegan>0:wip/R-cran-vegan

# From Qiime 1.8.0 port
RUN_DEPENDS+=	microbiomeutil>=r20110519:wip/microbiomeutil \
		cdbfasta>=2010.07.22:biology/cdbfasta

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LINUX=	yes	# For uclust closed-source binary
USE_JAVA=	yes	# rdp-classifier jar path
USES=		iconv python:2 shebangfix
SHEBANG_FILES=	setup.py qiime/*.py qiime/*/*.py scripts/*.py \
		tests/*.py tests/*/*.py
USE_PYTHON=	distutils autoplist

# Does not work for uclust
#USE_GITHUB=	yes
#GH_ACCOUNT=	biocore

SUB_FILES=	pkg-message qiime-env.csh qiime-env.sh qiime-test 
SUB_LIST+=	JAVAJARDIR=${JAVAJARDIR}

# start_parallel_jobs.py is for multithreaded?
post-patch:
	@${REINPLACE_CMD} \
		-e 's|qiime_scripts_dir|& ${PREFIX}/bin|g' \
		-e 's|cluster_jobs_fp|& ${PREFIX}/bin/start_parallel_jobs.py|g' \
		${WRKSRC}/qiime/support_files/qiime_config
	@${REINPLACE_CMD} \
		-e 's|#!/usr/bin/env python|${PYTHON_CMD}|g' \
		${WRKSRC}/scripts/make_qiime_py_file.py
	@${REINPLACE_CMD} \
		-e "s|'python'|'${PYTHON_CMD}'|g" \
		${WRKSRC}/tests/all_tests.py

# In theory, vsearch could work in place of usearch with few or no changes
#post-patch-VSEARCH-on:
#	@${REINPLACE_CMD} -e 's|usearch|vsearch|g' ${WRKSRC}/

# FIXME: INSTALL_PROGRAM complains when trying to strip a Linux binary.
# Is there a proper way to install them?
post-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/uclustq1.2.22_i86linux64 \
		${STAGEDIR}${PREFIX}/bin/uclust
	cd ${WRKSRC} && ${COPYTREE_BIN} tests ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} \
		${WRKDIR}/qiime-test \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKDIR}/qiime-env.csh \
		${WRKDIR}/qiime-env.sh \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
