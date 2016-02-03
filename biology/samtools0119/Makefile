# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	samtools
PORTVERSION=	0.1.19
CATEGORIES=	biology science
# Prevent pkg upgrade from replacing this with samtools 1.x
PKGNAMESUFFIX=	01
MASTER_SITES=	SF

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Generic format for storing large nucleotide sequence alignments

LICENSE=	MIT

USES=		gmake tar:bzip2 perl5 python:run shebangfix
SHEBANG_FILES=	misc/*.pl

ALL_TARGET=	all-recur razip

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|/software/bin/python|${LOCALBASE}/bin/python|g" \
		${WRKSRC}/misc/*.py
.if ${OSVERSION} < 1000000
	${REINPLACE_CMD} -e 's|expl|exp|g' -e 's|logl|log|g' \
		${WRKSRC}/errmod.c ${WRKSRC}/bcftools/prob1.c
.endif

WITH_DEBUG=	yes

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samtools ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/razip ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bcftools/bcftools ${STAGEDIR}${PREFIX}/bin
.for f in ace2sam bamcheck maq2sam-long maq2sam-short md5fa md5sum-lite wgsim
	${INSTALL_PROGRAM} ${WRKSRC}/misc/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/misc/*.pl ${WRKSRC}/misc/plot-bamcheck \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/*.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/*.lua ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libbam.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/samtools.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/include/bam
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/bam

.include <bsd.port.post.mk>
