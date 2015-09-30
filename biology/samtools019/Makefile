# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	samtools
PORTVERSION=	0.1.19
CATEGORIES=	biology science
MASTER_SITES=	SF

# FIXME: Check complete deps
# Just for speed: Recent GCC has better optimizer
# USE_GCC=	yes
USES=		gmake tar:bzip2 perl5 python:run shebangfix
SHEBANG_FILES=	misc/*.pl

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	Generic format for storing large nucleotide sequence alignments

ALL_TARGET=	all-recur razip

# FIXME: Find expl and logl somewhere to avoid reducing precision
post-patch:
	${REINPLACE_CMD} -e 's|expl|exp|g' -e 's|logl|log|g' \
		${WRKSRC}/errmod.c ${WRKSRC}/bcftools/prob1.c
	${REINPLACE_CMD} -e "s|/software/bin/python|${LOCALBASE}/bin/python|g" \
		${WRKSRC}/misc/*.py

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

.include <bsd.port.mk>
