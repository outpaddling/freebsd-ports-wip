# $FreeBSD$

PORTNAME=	graph-tool
DISTVERSION=	2.27
CATEGORIES=	wip graphics python
MASTER_SITES=	https://downloads.skewed.de/graph-tool/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python module for manipulation and statistical analysis of graphs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		${PY_BOOST} \
		libexpat.so:textproc/expat2 \
		libCGAL.so:math/cgal

# https://git.skewed.de/count0/graph-tool/wikis/installation-instructions#manual-compilation
# The sparsehash template library (optional, but recommended).
# The GTK+ 3, cairomm, pycairo and matplotlib libraries, used for graph drawing (optional).

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0.7.0:math/py-numpy@${PY_FLAVOR}

# Check python version requirement
USES=		python tar:bz2
USE_PYTHON=	autoplist distutils

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-boost-python=boost_python27

.include <bsd.port.mk>
