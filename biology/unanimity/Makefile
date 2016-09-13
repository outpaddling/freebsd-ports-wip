# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	unanimity
# PORTVERSION=	2016.08.31
PORTVERSION=	2016.09.13
CATEGORIES=	biology
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Consensus library and applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pbseqan==${PORTVERSION}:/usr/wip/biology/pbseqan \
		pbbam==${PORTVERSION}:/usr/wip/biology/pbbam \
		pbcopper==${PORTVERSION}:/usr/wip/biology/pbcopper
LIB_DEPENDS=	libhts.so:biology/htslib

USES=		cmake python
# USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
# GH_TAGNAME=	0b166c4
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
		-Dpbcopper_LIBRARIES="-l${LOCALBASE}/lib -lcopper"

CMAKE_VERBOSE=	yes
MAKE_JOBS_UNSAFE=	yes
# gcc: stoul is not a member of std
# http://stackoverflow.com/questions/26832199/getting-gcc-in-c11-mode-to-work-on-freebsd
# CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH -D_GLIBCXX_USE_C99_MATH_TR1

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

.include <bsd.port.mk>
