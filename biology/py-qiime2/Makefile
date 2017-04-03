# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# TODO:
# Patch setup.py to avoid downloading files during build phase
#     Remaining: sortmerna, suma_package, swarm
# Finish adding deps

PORTNAME=	qiime2
PORTVERSION=	2017.2.0
CATEGORIES=	biology
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DISTFILES=	${PORTVERSION}${EXTRACT_SUFX} \
		uclustq1.2.22_i86linux64
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Quantitative Insights Into Microbial Ecology

LICENSE=	GPLv2

# FIXME: These deps from from QIIME 1
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
#

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.9.0:math/py-numpy \
		${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy \
		${PKGNAMEPREFIX}scikit-bio==0.2.3:/usr/wip/biology/py-scikit-bio-0.2.3 \
		pycogent>=1.5.3:biology/pycogent \
		${PKGNAMEPREFIX}natsort>0:devel/py-natsort \
		${PKGNAMEPREFIX}matplotlib>=1.1.0:math/py-matplotlib \
		${PKGNAMEPREFIX}pynast==1.2.2:/usr/wip/biology/py-pynast \
		${PKGNAMEPREFIX}qcli>=0.1.1:/usr/wip/biology/py-qcli \
		${PKGNAMEPREFIX}gdata>=2.0.18:devel/py-gdata \
		${PKGNAMEPREFIX}biom-format>=2.1.4:biology/py-biom-format \
		${PKGNAMEPREFIX}emperor>=0.9.51:/usr/wip/biology/py-emperor \
		${PKGNAMEPREFIX}burrito-fillings>=0.1.1:/usr/wip/biology/py-burrito-fillings \
		${PKGNAMEPREFIX}pandas>=0.13.1:math/py-pandas \
		${PKGNAMEPREFIX}burrito>=0.9.1:/usr/wip/biology/py-burrito \
		${PKGNAMEPREFIX}qiime-default-reference>=0.1.2:/usr/wip/biology/py-qiime-default-reference \
		${PKGNAMEPREFIX}ipython>0:devel/ipython \
		${PKGNAMEPREFIX}sphinx>=0.3:textproc/py-sphinx \
		ghc:lang/ghc

# Unbundled
BUILD_DEPENDS+=	FastTree>=2.1.7:biology/fasttree \
		sortmerna==2.0:/usr/wip/biology/sortmerna \
		sumaclust>=1.0.00:/usr/wip/biology/sumaclust \
		swarm==1.2.19:/usr/wip/biology/swarm

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
		vsearch:/usr/wip/biology/vsearch

# Not listed as a dep, but tests fail without it
# Newer rdp-classifier may work.  all_tests.py failed with 2.12.
# java.lang.NoClassDefFoundError: org/apache/commons/cli/...
RUN_DEPENDS+=	muscle>=3.8.31:biology/muscle \
		rdp-classifier22==2.2:/usr/wip/biology/rdp-classifier-2.2 \
		infernal==1.0.2:/usr/wip/biology/infernal102 \
		rtax:/usr/wip/biology/rtax \
		mothur:/usr/wip/biology/mothur \
		blat>0:biology/blat \
		fastq-join>0:/usr/wip/biology/fastq-join \
		R-cran-ape>0:/usr/wip/biology/R-cran-ape \
		R-cran-optparse>0:/usr/wip/devel/R-cran-optparse \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		R-cran-randomForest>0:devel/R-cran-randomForest \
		R-cran-vegan>0:/usr/wip/biology/R-cran-vegan

# From Qiime 1.8.0 port
RUN_DEPENDS+=	microbiomeutil>=r20110519:/usr/wip/biology/microbiomeutil \
		cdbfasta>=2010.07.22:biology/cdbfasta

# QIIME 2 plugins
BUILD_DEPENDS=	${PKGNAMEPREFIX}q2-vsearch>=0:/usr/wip/biology/py-q2-vsearch \
		${PKGNAMEPREFIX}q2-deblur>=0:/usr/wip/biology/py-q2-deblur \
		${PKGNAMEPREFIX}q2-feature-classifier>=0:/usr/wip/biology/py-q2-feature-classifier

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LINUX=	yes	# For uclust closed-source binary
USE_JAVA=	yes	# rdp-classifier jar path
USES=		iconv python:2
USE_PYTHON=	distutils

USE_GITHUB=	yes

SUB_FILES=	pkg-message qiime-env.csh qiime-env.sh qiime-test 
SUB_LIST+=	JAVAJARDIR=${JAVAJARDIR}

post-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/uclustq1.2.22_i86linux64 \
		${STAGEDIR}${PREFIX}/bin/uclust
	cd ${WRKSRC}/qiime2 && ${COPYTREE_BIN} tests ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} \
		${WRKDIR}/qiime-test \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKDIR}/qiime-env.csh \
		${WRKDIR}/qiime-env.sh \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
