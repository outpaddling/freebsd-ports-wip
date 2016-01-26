# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# To-do:
#	Unbundle collectl (low priority)

PORTNAME=	trinity
PORTVERSION=	2.1.1
CATEGORIES=	biology java

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Trinity assembles transcript sequences from Illumina RNA-Seq data

LICENSE=	BSD3CLAUSE

USES=		gmake perl5 shebangfix dos2unix	compiler:openmp
SHEBANG_FILES=	util/*/*.sh \
		util/*/*.pl \
		Chrysalis/*.pl \
		trinity-plugins/collectl/build_collectl.sh
DOS2UNIX_FILES=	PerlLib/HPC/GridRunner.pm \
		PerlLib/HPC/SLURM_handler.pm
USE_JAVA=	yes
JAVA_VERSION=	1.7 1.6

USE_GITHUB=	yes
GH_ACCOUNT=	trinityrnaseq
GH_PROJECT=	trinityrnaseq
GH_TAGNAME=	v${PORTVERSION}

ONLY_FOR_ARCHS=	amd64

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp -Wl,-rpath=${_GCC_RUNTIME}

# Trinity core programs: Inchworm, Chrysalis, Butterfly

# Bundled plugins: Trinity is very sensitive to having the correct versions
# of some of these.  Test thoroughly if you change any of them.
# collectl 3.7.4
# samtools 0.1.19 (must use this version: 1.x does not work well)
# jellyfish 2.1.4 (2.2.0 seems OK)
# parafly 0.1 (determined from config.h)
# fastool 7c3e034f05 Nov 18 2013 commit on Github
# htslib 1.2.1
# slclust unknown (last version on SF is 02022010)
# Trimmomatic 0.32

BUILD_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils \
		bowtie:/usr/wip/biology/bowtie \
		samtools01==0.1.19:/usr/wip/biology/samtools0119 \
		jellyfish>=2.1.4:/usr/wip/biology/jellyfish2 \
		ParaFly:/usr/wip/sysutils/parafly \
		fastool:${PORTSDIR}/biology/fastool \
		TransDecoder.Predict:/usr/wip/biology/p5-transdecoder \
		slclust:/usr/wip/biology/slclust \
		Trimmomatic>=0.32:/usr/wip/biology/trimmomatic \
		rsem>=1.2.22:/usr/wip/biology/rsem
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libhts.so:${PORTSDIR}/biology/htslib

LIBEXEC_DIR=	${PREFIX}/libexec/trinity
PLUGINS_DIR=	${LIBEXEC_DIR}/trinity-plugins

WRKSRC=		${WRKDIR}/${PORTNAME}rnaseq-${PORTVERSION}

post-patch:
	# General changes to respect env
	${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${WRKSRC}/Chrysalis/Makefile* \
		${WRKSRC}/trinity-plugins/fstrozzi-Fastool-7c3e034f05/Makefile \
		${WRKSRC}/trinity-plugins/slclust/src/Makefile
	${REINPLACE_CMD} \
		-e 's|make |${MAKE} |g' \
		${WRKSRC}/trinity-plugins/collectl/build_collectl.sh

	# Change paths for plugins installed separately
	${REINPLACE_CMD} \
		-e 's|$$FindBin::Bin|$$FindBin::Bin/../libexec/trinity|g' \
		-e 's|$$FindBin::RealBin|$$FindBin::RealBin/../libexec/trinity|g' \
		-e 's|$$ROOTDIR/trinity-plugins/BIN|&:$$JELLYFISH_DIR/bin:$$FASTOOL_DIR|g' \
		-e 's|$$JELLYFISH_DIR/bin/jellyfish|jellyfish|g' \
		-e 's|$$FASTOOL_DIR/fastool|fastool|g' \
		-e 's|$$ROOTDIR/trinity-plugins/parafly/bin/ParaFly|ParaFly|g' \
		-e 's|$$ROOTDIR/trinity-plugins/Trimmomatic/trimmomatic.jar|${JAVAJARDIR}/trimmomatic.jar|g' \
		-e 's|$$ROOTDIR/trinity-plugins/Trimmomatic|${LOCALBASE}/share/Trimmomatic|g' \
		${WRKSRC}/Trinity

	# Utility scripts have some hard-coded paths as well
	${REINPLACE_CMD} -i '' \
		-e 's|$$JELLYFISH_DIR/bin/jellyfish|jellyfish|g' \
		-e 's|$$FASTOOL_DIR/fastool|fastool|g' \
		${WRKSRC}/util/insilico_read_normalization.pl
	${REINPLACE_CMD} -i '' \
		-e 's|$$JELLYFISH_DIR/bin/jellyfish|jellyfish|g' \
		${WRKSRC}/util/misc/run_jellyfish.pl
	${REINPLACE_CMD} -i '' \
		-e 's|$$FindBin::Bin/../../trinity-plugins/Trimmomatic/trimmomatic.jar|${JAVAJARDIR}/trimmomatic.jar|g' \
		-e 's|/seq/regev_genome_portal/SOFTWARE/BIN/trimmomatic.jar|${JAVAJARDIR}/trimmomatic.jar|g' \
		${WRKSRC}/util/misc/run_trimmomatic_qual_trimming.pl

	${REINPLACE_CMD} \
		-e "s|-lm -pthread|-lm -pthread -Wl,-rpath=${_GCC_RUNTIME}|g" \
		${WRKSRC}/Chrysalis/Makefile
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++ \
		${WRKSRC}/Chrysalis/Makefile_${CXX}
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++_x86_64 \
		${WRKSRC}/Chrysalis/Makefile_${CXX}_x86_64
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++_i386 \
		${WRKSRC}/Chrysalis/Makefile_${CXX}_i386

	# Remove absolute paths to Trinity command
	${REINPLACE_CMD} \
		-e 's|$$BASEDIR/Trinity|Trinity|g' \
		${WRKSRC}/util/run_Trinity_edgeR_pipeline.pl
	${REINPLACE_CMD} -i '' \
		-e 's|$$FindBin::Bin/../../Trinity|Trinity|g' \
		${WRKSRC}/util/support_scripts/write_partitioned_trinity_cmds.pl

# Some scripts are not available during patch stage
post-build:
	${REINPLACE_CMD} -i '' -e "s|/usr/bin/perl|${LOCALBASE}/bin/perl|g" \
		${WRKSRC}/trinity-plugins/collectl/bin/collectl \
		${WRKSRC}/trinity-plugins/collectl/bin/*.pl

# FIXME: More may need to be installed
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Trinity ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Chrysalis
	cd ${WRKSRC}/Chrysalis && \
		${INSTALL_PROGRAM} BreakTransByPairs Chrysalis \
			CreateIwormFastaBundle \
			GraphFromFasta GraphFromFasta_MPI \
			IsoformAugment JoinTransByPairs QuantifyGraph \
			ReadsToTranscripts ReadsToTranscripts_MPI \
			ReadsToTranscripts_MPI_chang RunButterfly \
			TranscriptomeFromVaryK checkLock \
			${STAGEDIR}${LIBEXEC_DIR}/Chrysalis
	${INSTALL_SCRIPT} ${WRKSRC}/Chrysalis/ReadsToComponents.pl \
		${STAGEDIR}${LIBEXEC_DIR}/Chrysalis

	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Inchworm/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Inchworm/bin/* \
		${STAGEDIR}${LIBEXEC_DIR}/Inchworm/bin

	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Butterfly
	${INSTALL_SCRIPT} ${WRKSRC}/Butterfly/Butterfly.jar \
		${STAGEDIR}${LIBEXEC_DIR}/Butterfly

	cd ${WRKSRC} && ${COPYTREE_BIN} PerlLib \
		${STAGEDIR}${LIBEXEC_DIR}

	cd ${WRKSRC} && ${COPYTREE_BIN} util \
		${STAGEDIR}${LIBEXEC_DIR}

	${MKDIR} \
		${STAGEDIR}${PLUGINS_DIR}/collectl \
		${STAGEDIR}${PLUGINS_DIR}/scaffold_iworm_contigs
	cd ${WRKSRC}/trinity-plugins/collectl && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PLUGINS_DIR}/collectl
	cd ${WRKSRC}/trinity-plugins && \
		${COPYTREE_BIN} GAL_0.2.1 ${STAGEDIR}${PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/trinity-plugins/scaffold_iworm_contigs/scaffold_iworm_contigs \
		${STAGEDIR}${PLUGINS_DIR}/scaffold_iworm_contigs

	cd ${WRKSRC}/sample_data && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
