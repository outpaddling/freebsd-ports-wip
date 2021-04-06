
PORTNAME=	blasr
DISTVERSION=	g20180411
#DISTNAME=smrtanalysis
#DISTVERSION=	4.0.0
#DISTVERSIONSUFFIX=	-121-geab53fd
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio(R) long read aligner

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	git:devel/git	# Get tag with git describe
LIB_DEPENDS=	libhdf5-18.so:science/hdf5-18 \
		libsz.so:science/szip \
		libblasr.so:wip/blasr_libcpp \
		libcurl.so:ftp/curl

USES=		cmake:outsource tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	eab53fd

CMAKE_ARGS=	-DHDF5_INCLUDE_DIRS:STRING=${LOCALBASE}/include/hdf5-18 \
		-DHDF5_LIBRARIES:STRING=${LOCALBASE}/lib \
		-DPacBioBAM_INCLUDE_DIRS:STRING=${LOCALBASE}/include \
		-DPacBioBAM_LIBRARIES:STRING=${LOCALBASE}/lib
MAKE_ENV=	GH_TAGNAME=${GH_TAGNAME}

.include <bsd.port.mk>
