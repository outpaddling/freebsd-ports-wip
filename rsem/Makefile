# Test new versions with Trinity before upgrading

PORTNAME=	rsem
PORTVERSION=	1.2.30
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

RUN_DEPENDS=	Rscript:math/R

# Gmake is for bundled samtools, which contains modifications for rsem.
# Should be unbundled in the future.
# Make sure all rsem programs use libexec/rsem/samtools
USES=		gmake perl5 python shebangfix
USE_PERL5=	run
SHEBANG_FILES=	convert-sam-for-rsem \
		extract-transcript-to-gene-map-from-trinity \
		rsem-calculate-expression \
		rsem-control-fdr \
		rsem-gen-transcript-plots \
		rsem-generate-data-matrix \
		rsem-generate-ngvector \
		rsem-plot-model \
		rsem-plot-transcript-wiggles \
		rsem-prepare-reference \
		rsem-run-ebseq \
		rsem_perl_utils.pm \
		rsem-gff3-to-gtf \
		rsem-refseq-extract-primary-assembly

USE_GITHUB=	yes
GH_ACCOUNT=	deweylab
GH_PROJECT=	RSEM

#WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

MAKE_ENV+=	libexecdir=${PREFIX}/libexec \
		perl_mod_dir=${PREFIX}/${SITE_PERL_REL}/rsem \
		LDL_LIB=""

post-patch:
	@${REINPLACE_CMD} -e \
		's|use lib $$FindBin::RealBin|use lib "${SITE_PERL}/rsem"|' \
		${WRKSRC}/rsem*
	@${REINPLACE_CMD} -e 's|samtools|${PREFIX}/libexec/rsem/samtools|g' \
		${WRKSRC}/rsem-calculate-expression \
		${WRKSRC}/rsem-plot-transcript-wiggles

post-stage:
	${RM} -rf ${STAGEDIR}${PREFIX}/bin/samtools-*

.include <bsd.port.mk>
