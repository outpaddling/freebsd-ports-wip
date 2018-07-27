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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/megahit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/megahit_* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
