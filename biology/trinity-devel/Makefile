# New ports collection makefile for:	trinity
# Date created:		2013-05-22
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	trinityrnaseq
PORTVERSION=	2.0.4
CATEGORIES=	biology
MASTER_SITES=	http://github.com/trinityrnaseq/trinityrnaseq/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	RNA sequence assembly

USES=		gmake perl5 shebangfix dos2unix
SHEBANG_FILES=	util/*/*.sh \
		util/*/*.pl \
		Chrysalis/*.pl
DOS2UNIX_FILES=	PerlLib/HPC/GridRunner.pm \
		PerlLib/HPC/SLURM_handler.pm
# Requires OpenMP.
USE_GCC=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7 1.6

ONLY_FOR_ARCHS=	amd64

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp -Wl,-rpath=${_GCC_RUNTIME}
MAKE_FLAGS+=	FORCE_UNSAFE_CONFIGURE=1

BUILD_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils \
		bowtie:/usr/wip/biology/bowtie111 \
		samtools:/usr/wip/biology/samtools \
		jellyfish>=2.1.4:/usr/wip/biology/jellyfish2 \
		ParaFly:/usr/wip/sysutils/parafly \
		fastool:/usr/wip/biology/fastool \
		TransDecoder.Predict:/usr/wip/biology/p5-transdecoder \
		slclust:/usr/wip/biology/slclust
#		rsem:/usr/wip/biology/rsem
#		/usr/wip/biology/trinotate

LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

MAKE_JOBS_UNSAFE=	yes

LIBEXEC_DIR=	${PREFIX}/libexec/trinity
PLUGINS_DIR=	${LIBEXEC_DIR}/trinity-plugins

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	# General changes to respect env
	${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${WRKSRC}/Chrysalis/Makefile* \
		${WRKSRC}/trinity-plugins/fstrozzi-Fastool-7c3e034f05/Makefile \
		${WRKSRC}/trinity-plugins/slclust/src/Makefile
	${REINPLACE_CMD} \
		-e 's|/bin/bash|/usr/bin/env bash|g' \
		-e 's|make |${GMAKE} |g' \
		${WRKSRC}/trinity-plugins/collectl/build_collectl.sh

	# Trinity paths, etc.
	${REINPLACE_CMD} \
		-e 's|$$FindBin::Bin|$$FindBin::Bin/../libexec/trinity|g' \
		${WRKSRC}/Trinity
	${REINPLACE_CMD} \
		-e 's|$$FindBin::RealBin|$$FindBin::RealBin/../libexec/trinity|g' \
		${WRKSRC}/Trinity
	${REINPLACE_CMD} \
		-e 's|$$ROOTDIR/trinity-plugins/jellyfish|${LOCALBASE}|g' \
		${WRKSRC}/Trinity
	${REINPLACE_CMD} \
		-e 's|$$ROOTDIR/trinity-plugins/parafly/bin/ParaFly|${LOCALBASE}/bin/ParaFly|g' \
		${WRKSRC}/Trinity
	${REINPLACE_CMD} \
		-e 's|$$ROOTDIR/trinity-plugins/fastool|${LOCALBASE}/bin|g' \
		${WRKSRC}/Trinity

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
		${WRKSRC}/PerlLib/HPC/GridRunner.pm

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

	cd ${WRKSRC} && ${COPYTREE_BIN} PerlLib \
		${STAGEDIR}${LIBEXEC_DIR}

	cd ${WRKSRC} && ${COPYTREE_BIN} util \
		${STAGEDIR}${LIBEXEC_DIR}

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/collectl
	cd ${WRKSRC}/trinity-plugins/collectl && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PLUGINS_DIR}/collectl

	${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/Trimmomatic

	cd ${WRKSRC}/trinity-plugins/Trimmomatic && \
		${COPYTREE_BIN} "adapters trimmomatic*.jar" \
		${STAGEDIR}${PLUGINS_DIR}/Trimmomatic

	cd ${WRKSRC}/sample_data && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
