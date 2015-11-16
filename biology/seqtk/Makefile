# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	seqtk
PORTVERSION=	2015.11.13
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#USE_GITHUB=	yes
#GH_ACCOUNT=	lh3
#GH_TAGNAME=	${PORTVERSION}

USES=	gmake

.include <bsd.port.pre.mk>

MAKE_JOBS_UNSAFE=	yes
# Just for speed: Recent GCC has better optimizer
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

PLIST_FILES=	bin/seqtk bin/trimadap
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seqtk \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap \
		${STAGEDIR}${PREFIX}/bin
.include <bsd.port.post.mk>
