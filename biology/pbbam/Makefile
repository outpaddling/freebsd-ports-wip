# Created by: Jason Bacon <bacon@outpaddling.cs.uwm.edu>
# $FreeBSD$

PORTNAME=	pbbam
PORTVERSION=	2016.09.07
CATEGORIES=	biology

MAINTAINER=	bacon@outpaddling.cs.uwm.edu
COMMENT=	PacBio BAM C++ library, with SWIG bindings

#LICENSE=	
#LICENSE_FILE=	

# FIXME: Guessing at actual boost lib needed
BUILD_DEPENDS=	doxygen>0:devel/doxygen
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs \
		libgtest.so:devel/googletest

USES=		cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	e46654e0e0b816230c16f4a6132c1feff633a62a

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

# FIXME: Disable tests for now.  Bound to bundled googletest.
CMAKE_ARGS+=	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
		-DHTSLIB_LIBRARIES:STRING=${LOCALBASE}/lib/libhts.so \
		-DPacBioBAM_build_tests:BOOL=off

# MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
