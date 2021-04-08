PORTNAME=		centrifuge
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.4
DISTVERSIONSUFFIX=	-beta
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Novel microbial classification engine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash

USES=		gmake shebangfix python:run
USE_GITHUB=	yes

SHEBANG_FILES=	centrifuge-build centrifuge-inspect centrifuge-download
GH_ACCOUNT=	infphilo

# FIXME: Fix asm block errors
MAKE_ENV=	POPCNT_CAPABILITY=0 DOCSDIR=${DOCSDIR}
# INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

.include <bsd.port.mk>
