# Test new versions with Trinity before upgrading

# FIXME: Find and install man pages
PORTNAME=	rsem
PORTVERSION=	1.2.28
DISTVERSIONPREFIX=      v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

RUN_DEPENDS=	Rscript:math/R

# For bundled samtools, which should be unbundled in the future, when RSEM
# depends only on an unmodified htslib.  Samtools and rsem developers
# are already communicating.
USES=		gmake perl5 python shebangfix
USE_PERL5=	run
SHEBANG_FILES=	convert-sam-for-rsem \
		extract-transcript-to-gene-map-from-trinity \
		rsem-calculate-expression \
		rsem-control-fdr \
		rsem-gen-transcript-plots \
		rsem-generate-data-matrix \
		rsem-generate-ngvector \
		rsem-gff3-to-gtf \
		rsem-plot-model \
		rsem-plot-transcript-wiggles \
		rsem-prepare-reference \
		rsem-refseq-extract-primary-assembly \
		rsem-run-ebseq \
		rsem_perl_utils.pm

USE_GITHUB=	yes
GH_ACCOUNT=	deweylab
GH_PROJECT=	RSEM

# WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

# FIXME: Hack for emmintrin.h not found on X120e
CXXFLAGS+=	-I/usr/include/clang/3.3/

MAKE_ENV+=	SITE_PERL=${SITE_PERL}

post-patch:
	${REINPLACE_CMD} -e \
		's|use lib $$FindBin::RealBin|use lib "${SITE_PERL}/rsem"|' \
		${WRKSRC}/rsem*

.include <bsd.port.mk>
