# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

# http://downloads.sourceforge.net/project/samtools/samtools/0.1.19/samtools-0.1.19.tar.bz2?r=http%3A%2F%2Fsourceforge.net%2Fprojects%2Fsamtools%2Ffiles%2F&ts=1400697947&use_mirror=hivelocity

PORTNAME=	samtools
PORTVERSION=	0.1.19
CATEGORIES=	biology science
MASTER_SITES=	SF

# FIXME: Check complete deps
USES=		gmake
USE_BZIP2=	yes
USE_PERL5=	run
USE_PYTHON=	yes

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	Generic format for storing large nucleotide sequence alignments

ALL_TARGET=	all-recur razip

# FIXME: Find expl and logl somewhere to avoid reducing precision
post-patch:
	${REINPLACE_CMD} -e 's|expl|exp|g' -e 's|logl|log|g' \
		${WRKSRC}/errmod.c ${WRKSRC}/bcftools/prob1.c

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

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
