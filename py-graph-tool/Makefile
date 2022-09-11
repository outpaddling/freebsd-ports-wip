PORTNAME=	graph-tool
DISTVERSION=	2.27
CATEGORIES=	wip graphics python
MASTER_SITES=	https://downloads.skewed.de/graph-tool/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python module for manipulation and statistical analysis of graphs
WWW=		https://graph-tool.skewed.de/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sparsehash>=0:devel/sparsehash \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.15.1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.14.1:graphics/py-cairo@${PY_FLAVOR}
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		${PY_BOOST} \
		libgmp.so:math/gmp \
		libexpat.so:textproc/expat2 \
		libCGAL.so:math/cgal
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.15.1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.14.1:graphics/py-cairo@${PY_FLAVOR}

USES=		gnome libtool pkgconfig python:3.6+ tar:bz2
USE_GNOME=	cairo cairomm libsigc++20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-boost-python=boost_python27 \
		--with-boost-libdir=${LOCALBASE}/lib
# Without this: configure: error: GNU MP not found (CGAL dependency)
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

.include <bsd.port.mk>
