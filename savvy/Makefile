# $FreeBSD$

PORTNAME=	savvy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Interface to various variant calling formats

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	shrinkwrap>=0:wip/shrinkwrap
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libhts.so:biology/htslib

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	statgen

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lbz2 -llzma -L${LOCALBASE}/lib -lcurl -lcrypto

.include <bsd.port.mk>
