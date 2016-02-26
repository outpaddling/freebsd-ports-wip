# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	sickle
PORTVERSION=	1.33
DISTVERSIONPREFIX=      v
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Windowed adaptive trimming tool for FASTQ files using quality

LICENSE=	GPLv2

# WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	najoshi
GH_PROJECT=	sickle

USES=		gmake

PLIST_FILES=	bin/sickle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sickle \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
