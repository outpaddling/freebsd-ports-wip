PORTNAME=	abyss
PORTVERSION=	2.1.0
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Assemble large genomes using short reads
WWW=		https://www.bcgsc.ca/platform/bioinfo/software/abyss

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# Dependencies for linked reads
#    ARCS to scaffold
#    Tigmint to correct assembly errors
# Optional dependencies
#    pigz for parallel gzip
#    samtools for reading BAM files
#    zsh for reporting time and memory usage

BUILD_DEPENDS=	sparsehash>0:devel/sparsehash
LIB_DEPENDS=	libmpi.so:net/openmpi \
		libboost_system.so:devel/boost-libs
RUN_DEPENDS=	pigz>0:archivers/pigz \
		samtools>0:biology/samtools \
		zsh>0:shells/zsh

USES=		autoreconf compiler:openmp shebangfix sqlite
SHEBANG_FILES=	bin/abyss-bowtie bin/abyss-bowtie2 bin/abyss-bwa \
		bin/abyss-bwasw bin/abyss-bwamem bin/abyss-kaligner \
		bin/abyss-pe bin/abyss-bloom-dist.mk bin/abyss-dida

GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bcgsc

CONFIGURE_ENV=	GHC=/nonexistent	# ghc build fails
CXXFLAGS+=	-DHAVE_LIBDL=1
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
