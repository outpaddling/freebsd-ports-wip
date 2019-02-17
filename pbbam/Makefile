# $FreeBSD: head/biology/pbbam/Makefile 487272 2018-12-12 01:35:33Z gerald $

PORTNAME=		pbbam
# Test new versions with biology/unanimity before upgrading!
DISTVERSION=		0.18.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio BAM C++ library, with SWIG bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>=1.60.0:devel/boost-libs
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

USES=		compiler:c++14-lang meson pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

# https://github.com/mesonbuild/meson/issues/2239
CONFIGURE_ENV=	BOOST_ROOT=${LOCALBASE}

.include <bsd.port.mk>
