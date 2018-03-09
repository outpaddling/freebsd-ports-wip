# $FreeBSD$

PORTNAME=	trimadap
PORTVERSION=	0.1p20170211
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lh3
GH_TAGNAME=	ddfef210563830d9193b40949da3523b6fb93003

PLIST_FILES=	bin/trimadap-mt

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CFLAGS+=	-msse2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
