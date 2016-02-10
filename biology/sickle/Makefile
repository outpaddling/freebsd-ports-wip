# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	sickle
PORTVERSION=	1.33
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Windowed adaptive trimming tool for FASTQ files using quality

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	najoshi
GH_PROJECT=	sickle
GH_TAGNAME=	v${PORTVERSION}
#GH_TAGNAME=	20d3cff7d7f483bd779aff75f861e93708c0a2b5

USES=		gmake

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/sickle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sickle \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
