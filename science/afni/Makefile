# Created by: Jason W. Bacon <jwbacon@tds.net>
# $FreeBSD: head/science/afni/Makefile 353973 2014-05-13 16:59:52Z antoine $

############################################################################
# http://www.neuro.mcw.edu/Ports has the latest source distribution from
#  which this port is built.  It will be updated as time permits.
#
# afni.nimh.nih.gov is the ultimate source for AFNI, and will always
# contain the latest source release.  If this port is not up to date,
# you can download the latest sources and build manually.

PORTNAME=	afni
PORTVERSION=	2012.04.17.2129
PORTREVISION=	8
CATEGORIES=	science biology graphics
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/AFNI/${PORTVERSION}/ \
		http://www.acadix.biz/Ports/distfiles/AFNI/${PORTVERSION}/
DISTFILES=	afni_src.tgz afni.1 3dClustBust.c \
		TTatlas+tlrc.BRIK.gz TTatlas+tlrc.HEAD CA_EZ_v1.5-July3107.tgz
DIST_SUBDIR=	AFNI-${PORTVERSION}
EXTRACT_ONLY=	afni_src.tgz CA_EZ_v1.5-July3107.tgz

MAINTAINER=	jwbacon@tds.net
COMMENT=	Advanced Functional Neuro Imaging

LICENSE=	GPLv2

LIB_DEPENDS=	libXm.so:${PORTSDIR}/x11-toolkits/open-motif \
		libR.so:${PORTSDIR}/math/R \
		libgsl.so:${PORTSDIR}/math/gsl \
		libnetcdf.so:${PORTSDIR}/science/netcdf-fortran
RUN_DEPENDS=	cjpeg:${PORTSDIR}/graphics/jpeg \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		whirlgif:${PORTSDIR}/graphics/whirlgif \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		endian:${PORTSDIR}/sysutils/endian \
		qhull:${PORTSDIR}/math/qhull5

CONFLICTS=	im-[0-9]* \
		nifticlib-[0-9]* \
		open-usp-tukubai-[0-9]*

USES=		gettext iconv gmake motif shebangfix perl5
SHEBANG_LANG=	tcsh
tcsh_OLD_CMD=	/bin/tcsh
tcsh_CMD=	/bin/tcsh
SHEBANG_FILES=	1dRplot 3dMEMA 3dMax 3dPAR2AFNI.pl 3dSignatures @1dDiffMag \
		@2dwarper @2dwarper.Allin @ANATICOR @AddEdge @AfniEnv \
		@AfniOrient2RAImap @AfniOrientSign @Align_Centers @Atlasize \
		@Center_Distance @CheckForAfniDset @CommandGlobb @DO.examples \
		@DTI_studio_reposition @DeblankFileNames @DiceMetric \
		@DriveAfni @DriveSuma @ElectroGrid @FS_roi_label @FSlabel2dset \
		@FromRAI @FullPath @GetAfniBin @GetAfniDims @GetAfniID \
		@GetAfniOrient @GetAfniPrefix @GetAfniRes @GetAfniView \
		@Install_InstaCorr_Demo @IsoMasks @MakeLabelTable @NoExt \
		@NoPound @NoisySkullStrip @Quiet_Talkers @ROI_Corr_Mat \
		@R_funclist @Reorder @RetinoProc @SUMA_AlignToExperiment @np \
		@SUMA_FSvolToBRIK @SUMA_Make_Spec_Caret @SUMA_Make_Spec_FS \
		@SUMA_Make_Spec_SF @ScaleVolume @ScriptCheck @Shift_Volume \
		@ShowDynamicRange @Spharm.examples \
		@SurfSmooth.HEAT_07.examples @TimeDiff @ToRAI @VolCenter \
		@align_partial_oblique @auto_align @auto_tlrc @build_afni_Xlib \
		@clean_help_dir @clip_volume @demo_prompt @escape- @fast_roi \
		@fix_FSsphere @float_fix @global_parse @help.AFNI @isOblique \
		@make_plug_diff @make_stim_file @parse_afni_name @parse_name \
		@radial_correlate @statauxcode @update.afni.binaries \
		AFNI_Batch_R ExamineXmat afni_run_R suma_change_spec

# Some prereqs use gcc anyway
USE_GCC=	yes

# NO_STAGE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not compile on sparc64: "undefined reference to '_mcount'"
.endif

USE_GL=		glw glu
USE_XORG=	xi
MAKE_ENV=	CC="${CC}"
MAKE_JOBS_UNSAFE=yes

WRKSRC=		${WRKDIR}/afni_src
ALL_TARGET=	vastness suma

###########################################################################
# Install parameters

SUB_FILES=	pkg-message afni.cshrc afni.profile

INSTALL_WRKSRC=	${WRKSRC}/BSD
PRESTAGE=	${WRKSRC}/prestage

X11R6_FILES=	coxplot/Makefile \
		coxplot/Makefile.f2c \
		3DEdge/src/Makefile \
		SUMA/SUMA_Makefile \
		edt_blur.c \
		suma_datasets.c \
		SUMA/SUMA_Load_Surface_Object.c \
		SUMA/SUMA_MiscFunc.c \
		SUMA/SUMA_ParseCommands.c \
		SUMA/GLUT/libglut/glut_event.c \
		SUMA/SUMA_Surface_IO.c

post-extract:
	@${CP} -f ${FILESDIR}/Makefile.FreeBSD_PORT ${WRKSRC}/Makefile
.for f in ${X11R6_FILES}
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${LOCALBASE}|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -E 's|AFNI_[0-9_]+|${PORTVERSION}|g' ${WRKSRC}/AFNI_label.h
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/afni.1 ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/3dClustBust.c ${WRKSRC}
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKDIR}/afni.1

post-build:
	${MKDIR} ${PRESTAGE}/bin \
		${PRESTAGE}/scripts \
		${PRESTAGE}/lib \
		${PRESTAGE}/include \
		${PRESTAGE}/trash \
		${PRESTAGE}/doc \
		${PRESTAGE}/share
	${MV}	${INSTALL_WRKSRC}/libf2c.a \
		${PRESTAGE}/trash
	${MV}	${INSTALL_WRKSRC}/*.a \
		${INSTALL_WRKSRC}/*.so \
		${PRESTAGE}/lib
	${MV}	${INSTALL_WRKSRC}/funstuff \
		${INSTALL_WRKSRC}/AFNI.*rc \
		${INSTALL_WRKSRC}/afnigui* \
		${PRESTAGE}/share
	${MV}	${INSTALL_WRKSRC}/*.h \
		${PRESTAGE}/include
	${MV}	${INSTALL_WRKSRC}/README* \
		${PRESTAGE}/doc
	${MV}	${INSTALL_WRKSRC}/abut ${INSTALL_WRKSRC}/afni_abut
	for binary in `${FILE} ${INSTALL_WRKSRC}/* | fgrep 'ELF' | ${AWK} -F ':' ' { print $$1 }'` ; do \
		${MV} $${binary} ${PRESTAGE}/bin ; \
	done
	${MV}	${INSTALL_WRKSRC}/* \
		${PRESTAGE}/scripts

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PREFIX}/lib/afni \
		${STAGEDIR}${PREFIX}/include/afni
	${INSTALL_DATA} ${PRESTAGE}/lib/* ${STAGEDIR}${PREFIX}/lib/afni
	${INSTALL_DATA} ${PRESTAGE}/include/* ${STAGEDIR}${PREFIX}/include/afni
	${CP} -R ${PRESTAGE}/share/* ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${PRESTAGE}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${PRESTAGE}/scripts/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/TTatlas* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/CA_EZ_v1.5-July3107/* ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/afni.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${PREFIX}/etc/mri
	${INSTALL_DATA} ${PRESTAGE}/doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/afni.cshrc ${WRKDIR}/afni.profile \
		${STAGEDIR}${PREFIX}/etc/mri
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
