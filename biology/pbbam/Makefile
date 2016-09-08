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
#		libgtest.so:devel/googletest
# BUILD_DEPENDS=	doxygen>0:devel/doxygen
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

USES=		cmake:outsource
#USES=		cmake:outsource ssl

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	e46654e0e0b816230c16f4a6132c1feff633a62a

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

# FIXME: Disable tests for now.  Bound to bundled googletest.
# FIXME: crypto and ssl hitchhiking on hts
CMAKE_ARGS+=	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
		-DHTSLIB_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhts -L/usr/lib -lcrypto -lssl" \
		-DPacBioBAM_build_tests:BOOL=OFF \
		-DPacBioBAM_build_docs:BOOL=OFF

# MAKE_JOBS_UNSAFE=	yes
# CMAKE_VERBOSE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
