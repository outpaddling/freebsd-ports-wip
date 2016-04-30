# New ports collection makefile for:	trinity
# Date created:		2013-05-22
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

# Unbundle:
# fstrozzi fastool
# trimmomatic
# transdecoder
# slclust
# rsem

PORTNAME=	trinity
PORTVERSION=	2014.04.13
CATEGORIES=	biology
MASTER_SITES=	https://sourceforge.net/projects/trinityrnaseq/files/
DISTNAME=	trinityrnaseq_r20140413p1

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA sequence assembly

# Depends on bowtie and jellyfish
ONLY_FOR_ARCH=	amd64

USES=		gmake perl5 shebangfix dos2unix
SHEBANG_FILES=	trinity-plugins/collectl/make_data_files.sh \
		trinity-plugins/collectl/plot.sh \
		trinity-plugins/collectl/timetable.sh \
		util/*/*.sh \
		util/*/*.pl \
		Chrysalis/*.pl
DOS2UNIX_FILES=	PerlLib/HTC/GridRunner.pm \
		PerlLib/HTC/SLURM_handler.pm
# Requires OpenMP.
USE_GCC=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7 1.6

ONLY_FOR_ARCHS=	amd64

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp -Wl,-rpath=${_GCC_RUNTIME}
MAKE_FLAGS+=	FORCE_UNSAFE_CONFIGURE=1

# Use samtools 0.1.19.  http://trinityrnaseq.github.io/
BUILD_DEPENDS+=	gsort:sysutils/coreutils \
		bash:shells/bash
RUN_DEPENDS+=	gsort:sysutils/coreutils \
		bowtie:/usr/wip/biology/bowtie \
		samtools01==0.1.19:/usr/wip/biology/samtools0119 \
		jellyfish:/usr/wip/biology/jellyfish \
		ParaFly:/usr/wip/sysutils/parafly
LIB_DEPENDS+=	libexecinfo.so:devel/libexecinfo

MAKE_JOBS_UNSAFE=	yes

LIBEXEC_DIR=	${PREFIX}/libexec/trinity
PLUGINS_DIR=	${LIBEXEC_DIR}/trinity-plugins

#FETCH_ARGS+=	-F

post-patch:
	# General changes to respect env
	${REINPLACE_CMD} -e "s|chrysalis_target jellyfish fastool parafly|chrysalis_target fastool|g" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${WRKSRC}/Makefile \
		${WRKSRC}/Chrysalis/Makefile* \
		${WRKSRC}/trinity-plugins/fastool/Makefile \
		${WRKSRC}/trinity-plugins/slclust/src/Makefile
	${REINPLACE_CMD} \
		-e 's|/bin/bash|/usr/bin/env bash|g' \
		-e 's|make |${GMAKE} |g' \
		${WRKSRC}/trinity-plugins/collectl/build_collectl.sh

	# Chrysalis
	${REINPLACE_CMD} \
		-e "s|-lm -pthread|-lm -pthread -Wl,-rpath=${_GCC_RUNTIME}|g" \
		${WRKSRC}/Chrysalis/Makefile
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++ \
		${WRKSRC}/Chrysalis/Makefile_${CXX}
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++_x86_64 \
		${WRKSRC}/Chrysalis/Makefile_${CXX}_x86_64
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++_i386 \
		${WRKSRC}/Chrysalis/Makefile_${CXX}_i386

	# GridRunner: ParaFly is intalled separately, so remove absolute path
	${REINPLACE_CMD} \
		-e 's|$$trin_home/trinity-plugins/parafly/bin/||g' \
		${WRKSRC}/PerlLib/HTC/GridRunner.pm

	# Remove absolute paths to Trinity command
	${REINPLACE_CMD} \
		-e 's|$$BASEDIR/Trinity|Trinity|g' \
		${WRKSRC}/util/run_Trinity_edgeR_pipeline.pl
	${REINPLACE_CMD} \
		-e 's|$$FindBin::Bin/../../Trinity|Trinity|g' \
		${WRKSRC}/util/support_scripts/GG_write_trinity_cmds.pl

# Some scripts are not available during patch stage
post-build:
	${REINPLACE_CMD} -i '' -e "s|/usr/bin/perl|${PREFIX}/bin/perl|g" \
		${WRKSRC}/trinity-plugins/collectl/bin/collectl \
		${WRKSRC}/trinity-plugins/collectl/bin/*.pl

# FIXME: Much more needs to be installed
# FIXME: Some of the 'plugins' should really be separate ports
#        Just dumping them to libexec/trinity for now
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Trinity ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}/Chrysalis
	cd ${WRKSRC}/Chrysalis && \
		${INSTALL_PROGRAM} BreakTransByPairs Chrysalis \
			GraphFromFasta IsoformAugment JoinTransByPairs \
			QuantifyGraph ReadsToTranscripts RunButterfly \
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

	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Trinity
	cd ${WRKSRC}/PerlLib && ${COPYTREE_BIN} '*' \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Trinity

	cd ${WRKSRC} && ${COPYTREE_BIN} util \
		${STAGEDIR}${LIBEXEC_DIR}

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/fastool
	${INSTALL_PROGRAM} ${WRKSRC}/trinity-plugins/fastool/fastool \
		${STAGEDIR}${PLUGINS_DIR}/fastool

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/collectl
	cd ${WRKSRC}/trinity-plugins/collectl && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PLUGINS_DIR}/collectl

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/coreutils
	cd ${WRKSRC}/trinity-plugins/coreutils && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PLUGINS_DIR}/coreutils

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/Trimmomatic

	cd ${WRKSRC}/trinity-plugins/Trimmomatic && \
		${COPYTREE_BIN} "adapters trimmomatic*.jar" \
		${STAGEDIR}${PLUGINS_DIR}/Trimmomatic

	cd ${WRKSRC}/sample_data && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
