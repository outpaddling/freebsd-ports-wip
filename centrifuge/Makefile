# $FreeBSD$

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
SHEBANG_FILES=	centrifuge-build centrifuge-inspect centrifuge-download
USE_GITHUB=	yes
GH_ACCOUNT=	infphilo

# FIXME: Fix asm block errors
MAKE_ENV=	POPCNT_CAPABILITY=0 DOCSDIR=${DOCSDIR}
# INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
