PORTNAME=		Jellyfish
DISTVERSIONPREFIX=	v
DISTVERSION=		2.3.0
PORTREVISION=		2
CATEGORIES=		wip biology
MASTER_SITES=		https://github.com/gmarcais/${PORTNAME}/releases/download/v2.3.0/
DISTNAME=		${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE-BSD-3-Clause
LICENSE_FILE_GPLv3=		${WRKSRC}/LICENSE-GPL-3.0

BUILD_DEPENDS=	yaggo:devel/yaggo
LIB_DEPENDS=	libhts.so:biology/htslib

# autoreconf, gettext needed for Github dist
USES=		compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
# USE_GITHUB=	yes

GNU_CONFIGURE=	yes
# GH_ACCOUNT=	gmarcais

INSTALL_TARGET=	install-strip
PLIST_SUB=	VER=${PORTVERSION}

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

# SSE code assumes amd64 features
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=--without-sse
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-faligned-new
.endif

do-test:
	@cd ${WRKSRC} && ${SH} ./test-driver --test-name big

.include <bsd.port.post.mk>
