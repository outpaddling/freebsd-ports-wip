
PORTNAME=	pysam
PORTVERSION=	0.8.3
CATEGORIES=	wip biology
MASTER_SITES=	http://github.com/pysam-developers/pysam/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python module for reading and manipulating samfiles

LICENSE=	MIT

# Currently does not build with cython 0.23
BUILD_DEPENDS=	cython:wip/cython022

# Tested with python 2.5 and 2.6
# Still not finding ncurses
USES=		ncurses python:2
USE_PYTHON=	distutils
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Patch for cython 0.23
post-patch:
	${REINPLACE_CMD} -e 's|ctypedef enum|cdef enum|g' \
		${WRKSRC}/pysam/chtslib.pxd

.include <bsd.port.mk>
