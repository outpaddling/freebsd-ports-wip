# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

# FIXME: Find and install man pages
# Make all rsem programs use libexec/rsem/samtools
PORTNAME=	rsem
PORTVERSION=	1.2.29
DISTVERSIONPREFIX=      v
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

RUN_DEPENDS=	Rscript:${PORTSDIR}/math/R

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
		rsem-plot-model \
		rsem-plot-transcript-wiggles \
		rsem-prepare-reference \
		rsem-run-ebseq \
		rsem_perl_utils.pm

USE_GITHUB=	yes
GH_ACCOUNT=	deweylab
GH_PROJECT=	RSEM

WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

MAKE_ENV+=	libexecdir=$(PREFIX)/libexec \
		perl_mod_dir=$(PREFIX)/$(SITE_PERL_REL)/rsem \
		LDL_LIB=""

post-patch:
	${REINPLACE_CMD} -e \
		's|use lib $$FindBin::RealBin|use lib "${SITE_PERL}/rsem"|' \
		${WRKSRC}/rsem*

post-stage:
	${RM} -rf ${STAGEDIR}${PREFIX}/bin/samtools-*

.include <bsd.port.mk>
