PORTNAME=		freebayes
DISTVERSION=		1.3.5
DISTVERSIONSUFFIX=	-src
MASTER_SITES=		https://github.com/freebayes/freebayes/releases/download/v${DISTVERSION}/
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

USES=		localbase:ldflags meson

WRKSRC=		${WRKDIR}/freebayes

# Works with external htslib, vcflib, tabixpp and seqlib now.
# Update those ports first.

.include <bsd.port.mk>
