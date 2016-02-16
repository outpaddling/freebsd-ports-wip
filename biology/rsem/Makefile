# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

# FIXME: Find and install man pages
PORTNAME=	rsem
PORTVERSION=	1.2.28
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

# For bundled samtools, which should be unbundled in the future, when RSEM
# depends only on an unmodified htslib.  Samtools and rsem developers
# are already communicating.
USES=		gmake perl5 shebangfix
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
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

# FIXME: Hack for emmintrin.h not found on X120e
CXXFLAGS+=	-I/usr/include/clang/3.3/

MAKE_ENV+=	SITE_PERL=${SITE_PERL}

post-patch:
	${REINPLACE_CMD} -e \
		's|use lib $$FindBin::RealBin|&/../${SITE_PERL_REL}/rsem|' \
		${WRKSRC}/rsem*

.include <bsd.port.mk>
