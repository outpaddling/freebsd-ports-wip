PORTNAME=		pbcopper
# DISTVERSION=	0.4.1 # Test with biology/unanimity before upgrading!
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.0 # Test with biology/unanimity before upgrading!
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Core C++ library for Pacific Biosciences tools
WWW=		https://github.com/PacificBiosciences/pbcopper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

# Meson needs BOOST_ROOT=${LOCALBASE}
# https://github.com/mesonbuild/meson/issues/2239
USES=		compiler:c++14-lang localbase meson
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbcopper.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbcopper.so.1.3
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbcopper.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbcopper.so.1

.include <bsd.port.mk>
