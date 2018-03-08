# $FreeBSD$

PORTNAME=	seqtk
DISTVERION=	2017.11.07
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	lh3
GH_TAGNAME=	d210c57d2ffa33da147e50f04f5aaaab1c160c8c

# Removed between 2017.02.11 and 2017.11.07
#WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

PLIST_FILES=	bin/seqtk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seqtk \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
