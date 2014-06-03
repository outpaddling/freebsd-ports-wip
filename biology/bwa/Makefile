# Created by: Jason Bacon
# $FreeBSD$

PORTNAME=	bwa
PORTVERSION=	0.7.9a
CATEGORIES=	biology science
MASTER_SITES=	SF/bio-bwa/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Burrows-Wheeler sequence aligner

LICENSE=	GPLv3

# Just for speed: Recent GCC has better optimizer
# USE_GCC=	yes
USES=		tar:bzip2 perl5 shebangfix
SHEBANG_FILES=	qualfa2fq.pl xa2multi.pl
USE_PERL5=	run

PLIST_FILES=	bin/bwa bin/qualfa2fq.pl bin/xa2multi.pl man/man1/bwa.1.gz

# Avoid #error in emmintrin.h
CFLAGS+=	-msse2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bwa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
