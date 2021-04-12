PORTNAME=	mshr
DISTVERSION=	2017.2.0
CATEGORIES=	wip
MASTER_SITES=	https://bitbucket.org/fenics-project/mshr/downloads/

MAINTAINER=	jwb@FreeBSD.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# cgal and tetgen are bundled right now.  Investigate unbundling.
# BUILD_DEPENDS=	tetgen>0:math/tetgen
# LIB_DEPENDS+=		libCGAL.so:math/cgal
# Yes, the ABI number on libdolfin is necessary.  Versions of all FEniCS
# components must match exactly.
LIB_DEPENDS=	libdolfin.so.${DISTVERSION}:wip/dolfin \
		libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		cmake:noninja python:3.6+
USE_LDCONFIG=	yes

.include <bsd.port.mk>
