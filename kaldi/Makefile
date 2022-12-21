PORTNAME=	kaldi
DISTVERSION=	0.0.0.9285
CATEGORIES=	wip audio

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Speech recognition toolkit
WWW=		https://example.com/kaldi

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libopenblas.so:math/openblas \
		libfst.so:math/openfst

USES=		libtool localbase:ldflags shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	configure
GH_ACCOUNT=	kaldi-asr
GH_TAGNAME=	be22248e3a166d9ec52c78dac945f471e7c3a8aa

# This is a mess of bundled software and no tags/releases
HAS_CONFIGURE=	yes
WRKSRC_SUBDIR=	src
CXX=		clang++
CONFIGURE_ARGS=	--fst-root=${LOCALBASE}

.include <bsd.port.mk>
