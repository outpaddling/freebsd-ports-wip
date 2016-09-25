# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# FIXME: Not performing as well as it should.  Profile the code.  Problem
# is likely in one of the libraries.

PORTNAME=	unanimity
PORTVERSION=	2016.09.13
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Consensus library and applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# FIXME: Currently requires git.  Should be patched out.
BUILD_DEPENDS=	pbseqan==${PORTVERSION}:/usr/wip/biology/pbseqan \
		pbbam==${PORTVERSION}:/usr/wip/biology/pbbam \
		pbcopper==${PORTVERSION}:/usr/wip/biology/pbcopper
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so.1.60.0:/usr/wip/devel/boost-libs

USES=		cmake python
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
