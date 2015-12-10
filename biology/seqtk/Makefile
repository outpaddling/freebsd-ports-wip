# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	seqtk
PORTVERSION=	4feb6e81444ab6bc44139dd3a125068f81ae4ad8
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	lh3
GH_TAGNAME=	${PORTVERSION}

USES=		gmake tar:xz

.include <bsd.port.pre.mk>

MAKE_JOBS_UNSAFE=	yes
# Just for speed: Recent GCC has better optimizer
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
CFLAGS+=	-msse2
.endif

PLIST_FILES=	bin/seqtk bin/trimadap
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seqtk \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap \
		${STAGEDIR}${PREFIX}/bin
.include <bsd.port.post.mk>
