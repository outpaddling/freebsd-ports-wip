# $FreeBSD$

PORTNAME=	pbbam
DISTVERSION=	0.18.0 # Test with biology/unanimity before upgrading!
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio BAM C++ library, with SWIG bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

USES=		compiler:c++14-lang localbase meson pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

# https://github.com/mesonbuild/meson/issues/2239
# CONFIGURE_ENV=	BOOST_ROOT=${LOCALBASE}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbbam.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbbam.so.0.18
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbbam.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbbam.so.0

.include <bsd.port.mk>
