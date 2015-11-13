# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	seqtk
PORTVERSION=	sgdb
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	lh3
GH_TAGNAME=	${PORTVERSION}

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

INSTALL_TARGET	=install-strip
#post-patch:
#	@${REINPLACE_CMD} -e 's|CXX\t*=|CXX\t?|g' ${WRKSRC}/Makefile
#	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
