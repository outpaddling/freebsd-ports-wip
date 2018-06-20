# $FreeBSD: head/biology/seqtk/Makefile 466379 2018-04-03 20:57:05Z jwb $

PORTNAME=		seqtk
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

PLIST_FILES=	bin/seqtk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seqtk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
