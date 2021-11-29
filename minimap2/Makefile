PORTNAME=		minimap2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.23
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pairwise aligner for genomic and spliced nucleotide sequences

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	Hard-coded SSE instructions

USES=		gmake localbase
USE_GITHUB=	yes

GH_ACCOUNT=	lh3

MAKE_ARGS+=	CFLAGS+=-Wextra
ALL_TARGET=	extra
INSTALL_TARGET=	install-strip

CFLAGS+=	-DUSE_SIMDE -DSIMDE_ENABLE_NATIVE_ALIASES

.include <bsd.port.mk>
