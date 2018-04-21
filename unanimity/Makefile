# $FreeBSD$

# FIXME: Not performing as well as it should.  Profile the code.  Problem
# is likely in one of the libraries.  Runs 30% faster on CentOS / gcc49
# on identical hardware (dual 3.0Ghz Xeon dual core, unixdev, centosdev).
# Rules out compiler.  Clang 3.4 and gcc49 produce same performance on
# unixdev.

PORTNAME=	unanimity
DISTVERSION=	g20180307
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Consensus library and applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# Sensitive to dependency versions, use latest commit for everything
BUILD_DEPENDS=	pbseqan==g20171002:wip/pbseqan \
		pbbam==g20180416:wip/pbbam \
		pbcopper==5.0.1p20180413:wip/pbcopper
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

USES=		cmake pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	6f11a13e1472b8c00337ba8c5e94bf83bdab31d6

CMAKE_ARGS+=	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
		-DHTSLIB_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhts" \
		-DPacBioBAM_INCLUDE_DIRS:STRING=${LOCALBASE}/include/pbbam \
		-DPacBioBAM_LIBRARIES:STRING="-L${LOCALBASE}/lib -lpbbam" \
		-DSEQAN_INCLUDE_DIRS:STRING=${LOCALBASE}/include/PacBio \
		-Dpbcopper_INCLUDE_DIRS=${LOCALBASE}/include \
		-Dpbcopper_LIBRARIES="-L${LOCALBASE}/lib -lpbcopper"

PLIST_FILES=	bin/arrow bin/ccs bin/gcpp

.include <bsd.port.mk>
