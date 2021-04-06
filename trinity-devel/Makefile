
PORTNAME=		trinity
DISTVERSIONPREFIX=	Trinity-v
DISTVERSION=		2.8.3
CATEGORIES=		wip biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trinity assembles transcript sequences from Illumina RNA-Seq data

LICENSE=	BSD3CLAUSE

# FIXME: Update these versions
# Trinity core programs: Inchworm, Chrysalis, Butterfly
# Bundled plugins: Trinity is very sensitive to having the correct versions
# of some of these.  Test thoroughly if you change any of them.
# collectl 4.1.0
# jellyfish 2.1.4 (2.2.0 seems OK)
# parafly 0.1 (determined from config.h)
# fastool 7c3e034f05 Nov 18 2013 commit on Github
# htslib 1.2.1
# slclust unknown (last version on SF is 02022010)
# Trimmomatic 0.32
# To-do:
#	Unbundle collectl (low priority)

BUILD_DEPENDS+=	gsort:sysutils/coreutils \
		bash:shells/bash \
		cmake:devel/cmake \
		slclust:biology/slclust \
		salmon:wip/salmon
RUN_DEPENDS+=	gsort:sysutils/coreutils \
		bowtie:biology/bowtie \
		bowtie2:biology/bowtie2 \
		samtools>=1.3:biology/samtools \
		jellyfish>=2.1.4:biology/jellyfish \
		ParaFly:sysutils/parafly \
		fastool:biology/fastool \
		TransDecoder.Predict:biology/p5-transdecoder \
		slclust:biology/slclust \
		trimmomatic>=0.32:biology/trimmomatic \
		rsem>=1.2.27:wip/rsem
LIB_DEPENDS+=	libhts.so:biology/htslib

USES=		compiler:openmp gmake perl5 python shebangfix
SHEBANG_FILES=	util/*/*.sh \
		util/*/*.pl \
		Chrysalis/analysis/*.pl \
		util/support_scripts/trinity_installer.py \
		util/misc/alt_GG_read_partitioning_JCornish/genwig.sh \
		util/misc/alt_GG_read_partitioning_JCornish/genwig2.py \
		util/misc/sim_test_framework/run_Trinity_eval.sh \
		util/misc/TPM_weighted_gene_length.py \
		Analysis/SuperTranscripts/*.py \
		Analysis/SuperTranscripts/*/*.py \
		Analysis/DifferentialExpression/cluster_sample_data/runMe.sh
USE_JAVA=	yes
# Check this
JAVA_VERSION=	1.8 1.7 1.6
USE_GITHUB=	yes
GH_ACCOUNT=	trinityrnaseq
GH_PROJECT=	trinityrnaseq

# Depends on bowtie and jellyfish2
# Should work on other 64-bit archs, but untested
ONLY_FOR_ARCH=	amd64

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp -Wl,-rpath=${_GCC_RUNTIME}
MAKE_JOBS_UNSAFE=	yes

EXAMPLES=	*
OPTIONS_DEFINE=	EXAMPLES

LIBEXEC_DIR=	${PREFIX}/libexec/trinity
PLUGINS_DIR=	${LIBEXEC_DIR}/trinity-plugins

post-patch:
	# General changes to respect env
	${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g" \
		-e "s|g++|${CXX}|g" \
		${WRKSRC}/Chrysalis/Makefile*

	${REINPLACE_CMD} \
		-e 's|$$FindBin::Bin|$$FindBin::Bin/../libexec/trinity|g' \
		-e 's|$$FindBin::RealBin|$$FindBin::RealBin/../libexec/trinity|g' \
		-e 's|$$ROOTDIR/trinity-plugins/BIN/ParaFly|ParaFly|g' \
		-e 's|$$ROOTDIR/trinity-plugins/Trimmomatic/trimmomatic.jar|${JAVAJARDIR}/trimmomatic.jar|g' \
		-e 's|$$ROOTDIR/trinity-plugins/Trimmomatic|${LOCALBASE}/share/Trimmomatic|g' \
		${WRKSRC}/Trinity

	${REINPLACE_CMD} -i '' \
		-e 's|$$JELLYFISH_DIR/bin/jellyfish|jellyfish|g' \
		${WRKSRC}/util/misc/run_jellyfish.pl

	${REINPLACE_CMD} -i '' \
		-e 's|$$FindBin::RealBin/../../trinity-plugins/Trimmomatic/trimmomatic.jar|${JAVAJARDIR}/trimmomatic.jar|g' \
		-e 's|/seq/regev_genome_portal/SOFTWARE/BIN/trimmomatic.jar|${JAVAJARDIR}/trimmomatic.jar|g' \
		${WRKSRC}/util/misc/run_trimmomatic_qual_trimming.pl

	${REINPLACE_CMD} \
		-e "s|-lm -pthread|-lm -pthread -Wl,-rpath=${_GCC_RUNTIME}|g" \
		${WRKSRC}/Chrysalis/Makefile

	# Remove absolute paths to Trinity command
	${REINPLACE_CMD} -i '' \
		-e 's|$$FindBin::Bin/../../Trinity|Trinity|g' \
		${WRKSRC}/util/support_scripts/write_partitioned_trinity_cmds.pl

# Some scripts are not available during patch stage
post-build:
	${REINPLACE_CMD} -i '' -e "s|/usr/bin/perl|${LOCALBASE}/bin/perl|g" \
		${WRKSRC}/trinity-plugins/COLLECTL/collectl/collectl \
		${WRKSRC}/trinity-plugins/COLLECTL/collectl/*.pl

# FIXME: More may need to be installed
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Trinity ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Chrysalis/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Chrysalis/bin/* \
		${STAGEDIR}${LIBEXEC_DIR}/Chrysalis/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Chrysalis/analysis/ReadsToComponents.pl \
		${STAGEDIR}${LIBEXEC_DIR}/Chrysalis/bin

	@${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Inchworm/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Inchworm/bin/* \
		${STAGEDIR}${LIBEXEC_DIR}/Inchworm/bin

	@${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Butterfly
	${INSTALL_SCRIPT} ${WRKSRC}/Butterfly/Butterfly.jar \
		${STAGEDIR}${LIBEXEC_DIR}/Butterfly

	cd ${WRKSRC} && ${COPYTREE_BIN} PerlLib \
		${STAGEDIR}${LIBEXEC_DIR}

	cd ${WRKSRC} && ${COPYTREE_BIN} util \
		${STAGEDIR}${LIBEXEC_DIR}

	cd ${WRKSRC} && ${COPYTREE_BIN} Analysis \
		${STAGEDIR}${LIBEXEC_DIR}

	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/scaffold_iworm_contigs
	${INSTALL_PROGRAM} ${WRKSRC}/trinity-plugins/scaffold_iworm_contigs/scaffold_iworm_contigs \
		${STAGEDIR}${PLUGINS_DIR}/scaffold_iworm_contigs

	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/BIN
	${INSTALL_PROGRAM} ${WRKSRC}/trinity-plugins/BIN/seqtk-trinity \
		${STAGEDIR}${PLUGINS_DIR}/BIN

	cd ${WRKSRC}/sample_data && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}

	${RLN} ${STAGEDIR}${PREFIX}/bin/Trinity \
		${STAGEDIR}${PREFIX}/libexec/trinity/Trinity

.include <bsd.port.mk>
