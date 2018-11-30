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

# https://git.skewed.de/count0/graph-tool/wikis/installation-instructions#manual-compilation
# The sparsehash template library (optional, but recommended).
# The GTK+ 3, cairomm, pycairo and matplotlib libraries, used for graph drawing (optional).
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		${PY_BOOST} \
		libgmp.so:math/gmp \
		libexpat.so:textproc/expat2 \
		libCGAL.so:math/cgal
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0.7.0:math/py-numpy@${PY_FLAVOR}

USES=		gnome libtool python tar:bz2
USE_GNOME=	cairo cairomm libsigc++20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

# --with-cgal=${LOCALBASE}
CONFIGURE_ARGS=	--with-boost-python=boost_python27 \
		--with-boost-libdir=${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
