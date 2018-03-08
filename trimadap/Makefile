# $FreeBSD$

PORTNAME=	trimadap
DISTVERSION=	2017.02.11
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	lh3
GH_TAGNAME=	ddfef210563830d9193b40949da3523b6fb93003

# Removed feb 2018
#WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

PLIST_FILES=	bin/trimadap-mt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
