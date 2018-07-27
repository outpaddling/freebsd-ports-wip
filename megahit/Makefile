# $FreeBSD$

PORTNAME=		megahit
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1.3
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra-fast single-node large and complex metagenomics assembly

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:openmp gmake python shebangfix
SHEBANG_FILES=	megahit
USE_GITHUB=	yes
GH_ACCOUNT=	voutcn

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/megahit \
		bin/megahit_asm_core \
		bin/megahit_sdbg_build \
		bin/megahit_toolkit

.include <bsd.port.mk>
