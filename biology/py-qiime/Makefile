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

LIB_DEPENDS+=libgmp.so:math/gmp
LIB_DEPENDS+=libffi.so:devel/libffi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LINUX=	yes	# For uclust closed-source binary
USES=		iconv python:2
USE_PYTHON=	distutils

PYDISTUTILS_PKGNAME=	qiime

# FIXME: Many of these are probably just run depends
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

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.9.0:math/py-numpy \
		${PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy \
		${PKGNAMEPREFIX}matplotlib>=1.1.0:math/py-matplotlib \
		pycogent>=1.5.3:biology/pycogent \
		${PKGNAMEPREFIX}natsort>0:devel/py-natsort \
		${PKGNAMEPREFIX}pynast==1.2.2:/usr/wip/biology/py-pynast \
		${PKGNAMEPREFIX}gdata>=2.0.18:devel/py-gdata \
		${PKGNAMEPREFIX}biom-format>=2.1.4:biology/py-biom-format \
		${PKGNAMEPREFIX}emperor>=0.9.51:/usr/wip/biology/py-emperor \
		${PKGNAMEPREFIX}scikit-bio==0.2.3:/usr/wip/biology/py-scikit-bio-0.2.3 \
		${PKGNAMEPREFIX}burrito-fillings>=0.1.1:/usr/wip/biology/py-burrito-fillings \
		${PKGNAMEPREFIX}pandas>=0.13.1:math/py-pandas \
		${PKGNAMEPREFIX}burrito>=0.9.1:/usr/wip/biology/py-burrito \

#		${PKGNAMEPREFIX}>=:/usr/wip/biology/ \
#		${PKGNAMEPREFIX}qcli>=0.1.1:/usr/wip/biology/py-qcli \
#		${PKGNAMEPREFIX}pyqi>=0.3.2:/usr/wip/biology/py-pyqi \
#		${PKGNAMEPREFIX}h5py>=2.3.0:science/py-h5py \
#		FastTree>=2.1.7:biology/fasttree \
#		muscle>=3.8.31:biology/muscle \
#		infernal>=1.0.2:/usr/wip/biology/infernal102 \
#		rdp-classifier=2.2:/usr/wip/biology/rdp-classifier-2.2 \
#		microbiomeutil>=r20110519:/usr/wip/biology/microbiomeutil \
#		cdbfasta>=2010.07.22:biology/cdbfasta \
#		sphinx-build:textproc/py-sphinx \
#		ghc:lang/ghc
#RUN_DEPENDS=	${BUILD_DEPENDS} \
#		ncbi-toolkit>=2012.06.20:biology/ncbi-toolkit \
#		cd-hit>=4.6.1:biology/cd-hit \
#		usearch6.1.544_i86linux32:/usr/wip/biology/linux-usearch-6.1

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
