
PORTNAME=	sickle
PORTVERSION=	1.33
DISTVERSIONPREFIX=      v
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Windowed adaptive trimming tool for FASTQ files using quality

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	najoshi
GH_PROJECT=	sickle

# Requires libz
USES=		gmake

PLIST_FILES=	bin/sickle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sickle \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
