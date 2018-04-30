# $FreeBSD$

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

.include <bsd.port.mk>
