# $FreeBSD: head/biology/pbcopper/Makefile 487272 2018-12-12 01:35:33Z gerald $

PORTNAME=		pbcopper
# Test new versions with biology/unanimity before upgrading!
DISTVERSION=		0.4.1
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Core C++ library for Pacific Biosciences tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		compiler:c++14-lang meson
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

# https://github.com/mesonbuild/meson/issues/2239
CONFIGURE_ENV=	BOOST_ROOT=${LOCALBASE}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbcopper.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbcopper.so.0.4
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbcopper.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbcopper.so.0

.include <bsd.port.mk>
