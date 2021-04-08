PORTNAME=	samtools
PORTVERSION=	0.1.19
CATEGORIES=	wip biology
MASTER_SITES=	SF
# Prevent pkg upgrade from replacing this with samtools 1.x
PKGNAMESUFFIX=	01

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generic format for storing large nucleotide sequence alignments

LICENSE=	MIT

USES=		gmake tar:bzip2 perl5 python:run shebangfix
SHEBANG_FILES=	misc/*.pl

ALL_TARGET=	all-recur razip

SAMPREFIX=	${PREFIX}/samtools0119

.include <bsd.port.pre.mk>

# Shebangfix doesn't recognize /software/bin/python
post-patch:
	${REINPLACE_CMD} -e "s|/software/bin/python|${PYTHON_CMD}|g" \
		${WRKSRC}/misc/*.py
.if ${OSVERSION} < 1000000
	${REINPLACE_CMD} -e 's|expl|exp|g' -e 's|logl|log|g' \
		${WRKSRC}/errmod.c ${WRKSRC}/bcftools/prob1.c
.endif

do-install:
	@${MKDIR} \
		${STAGEDIR}${SAMPREFIX}/bin \
		${STAGEDIR}${SAMPREFIX}/lib \
		${STAGEDIR}${SAMPREFIX}/man/man1 \
		${STAGEDIR}${SAMPREFIX}/include/bam
	${INSTALL_PROGRAM} ${WRKSRC}/samtools ${STAGEDIR}${SAMPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/razip ${STAGEDIR}${SAMPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bcftools/bcftools ${STAGEDIR}${SAMPREFIX}/bin
.for f in ace2sam bamcheck maq2sam-long maq2sam-short md5fa md5sum-lite wgsim
	${INSTALL_PROGRAM} ${WRKSRC}/misc/${f} ${STAGEDIR}${SAMPREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/misc/*.pl ${WRKSRC}/misc/plot-bamcheck \
		${STAGEDIR}${SAMPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/*.py ${STAGEDIR}${SAMPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/*.lua ${STAGEDIR}${SAMPREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libbam.a ${STAGEDIR}${SAMPREFIX}/lib
	${GZIP_CMD} ${WRKSRC}/samtools.1
	${INSTALL_MAN} ${WRKSRC}/samtools.1.gz ${STAGEDIR}${SAMPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${SAMPREFIX}/include/bam

.include <bsd.port.post.mk>
