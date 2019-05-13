# $FreeBSD$

PORTNAME=		jellyfish
PORTVERSION=		2.2.10
DISTVERSIONPREFIX=	v
PORTREVISION=		5
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yaggo:devel/yaggo
LIB_DEPENDS=	libhts.so:biology/htslib

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GH_ACCOUNT=	gmarcais
GH_PROJECT=	Jellyfish

INSTALL_TARGET=	install-strip

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.pre.mk>

# SSE code assumes amd64 features
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=--without-sse
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-faligned-new
.endif

.include <bsd.port.post.mk>
