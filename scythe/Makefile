PORTNAME=	scythe
PORTVERSION=	2016.02.10
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	3'-end adapter contaminant trimmer
WWW=		https://github.com/vsbuffalo/scythe

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	vsbuffalo
GH_TAGNAME=	20d3cff7d7f483bd779aff75f861e93708c0a2b5

USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

PLIST_FILES=	bin/scythe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scythe \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
