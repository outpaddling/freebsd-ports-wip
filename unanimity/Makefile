# $FreeBSD$
#
# FIXME: Not performing as well as it should.  Profile the code.  Problem
# is likely in one of the libraries.  Runs 30% faster on CentOS / gcc49
# on identical hardware (dual 3.0Ghz Xeon dual core, unixdev, centosdev).
# Rules out compiler.  Clang 3.4 and gcc49 produce same performance on
# unixdev.

PORTNAME=	unanimity
PORTVERSION=	2016.09.13
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Consensus library and applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# FIXME: Currently requires git.  Should be patched out.
BUILD_DEPENDS=	pbseqan==${PORTVERSION}:wip/pbseqan \
		pbbam==${PORTVERSION}:wip/pbbam \
		pbcopper==${PORTVERSION}:wip/pbcopper \
		boost-libs>=1.60.0:devel/boost-libs
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

USES=		cmake compiler:c++11-lang python
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	054c595

# FIXME: Searches /usr/local/include before /usr/local/include/PacBio
# so it will pick up the wrong seqan headers if biology/seqan is installed.
# Hopefully PacBio's seqan patches will be in the next seqan release.
CMAKE_ARGS+=	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
		-DHTSLIB_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhts" \
		-DPacBioBAM_INCLUDE_DIRS:STRING=${LOCALBASE}/include/pbbam \
		-DPacBioBAM_LIBRARIES:STRING="-L${LOCALBASE}/lib -lpbbam" \
		-DSEQAN_INCLUDE_DIRS:STRING=${LOCALBASE}/include/PacBio \
		-Dpbcopper_INCLUDE_DIRS=${LOCALBASE}/include \
		-Dpbcopper_LIBRARIES="-L${LOCALBASE}/lib -lpbcopper"

LDFLAGS+=	-L/usr/lib -lcrypto -lssl

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

.include <bsd.port.mk>
