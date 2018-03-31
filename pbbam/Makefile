# $FreeBSD$

PORTNAME=	pbbam
PORTVERSION=	0.0.0p20180322
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio BAM C++ library, with SWIG bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Add when tests are enabled	libgtest.so:devel/googletest
# FIXME: Guessing at actual boost lib needed
BUILD_DEPENDS=	boost-libs>=1.60.0:devel/boost-libs
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

USES=		cmake:outsource compiler:c++11-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	9f170446053144a2d4efe0a870e98bc41057e568

# FIXME: Disable tests for now.  Bound to bundled googletest.
CMAKE_ARGS+=	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
		-DHTSLIB_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhts" \
		-DPacBioBAM_build_tests:BOOL=OFF \
		-DPacBioBAM_build_docs:BOOL=OFF

LDFLAGS+=	-L/usr/lib -lcrypto -lssl

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
