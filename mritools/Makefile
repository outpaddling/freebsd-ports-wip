############################################################################
############################################################################
# Metaport for MRI software tools

PORTNAME=	mritools
PORTVERSION=	1.0
CATEGORIES=	wip science biology
MASTER_SITES=
DISTFILES=

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Metaport for MRI software tools

NO_BUILD=	"YES"

RUN_DEPENDS=

MAN1=		mritools.1

OPTIONS=        AFNI    "Advanced Functional Neural Imaging"            on \
		CARET5  "Computerized Anatomical Reconstruction/Editing" on \
		DTIQUERY "Stanford DTI Visualization tool"              on \
		FFMAP   "Functional Field Mapping Tools"                on \
		FREESURFER      "Cortical Surface Reconstruction"       on \
		FSL     "FMRIB Software Library"                        on \
		LENS    "Light Efficient Neural Network Simulator"      on \
		MATH    "Math/Stats tools"                              on \
		SCILAB  "Free Matlab-like system"                       on \
		SCRIPTS "Miscellaneous MCW scripts"                     on \
		SOUND   "Sound manipulation tools"                      on \
		SYSTOOLS "Miscellaneous system tools"                   on \
		TLV     "Unpacks scanner files"                         on

.include <bsd.port.pre.mk>

.if defined(WITH_MATH)
RUN_DEPENDS+=   randsign:../../math/randsign \
		1Dmean:../../science/1dmean \
		1dregression:../../science/1dregression \
		trialsto1D:../../science/trialsto1d
.endif

.if defined(WITH_SCRIPTS)
RUN_DEPENDS+=   ${LOCALBASE}/mri/scripts:../../misc/mcwscripts
.endif

.if defined(WITH_TLV)
RUN_DEPENDS+=   TLv:../../science/TLv
.endif

.if defined(WITH_SYSTOOLS)
RUN_DEPENDS+=   endian:sysutils/endian \
		eject:sysutils/mcweject
.endif

.if defined(WITH_SOUND)
RUN_DEPENDS+=   audacity:audio/audacity
.endif

.if defined(WITH_FFMAP)
RUN_DEPENDS+=   ffmap:../../science/ffmap \
		ffnhfilter:../../science/ffnhfilter \
		ffsectorstats:../../science/ffsectorstats \
		hilbplug2ffmap:../../science/hilbplug2ffmap \
		mkcolor3_caret_fim:../../science/mkcolor3_caret_fim \
		patchworks:../../science/patchworks
.endif

.if defined(WITH_LENS)
RUN_DEPENDS+=   lensnns:/usr/ports/math/lensnns
.endif

.if defined(WITH_AFNI)
RUN_DEPENDS+=   afni:../../science/afni
.endif

.if defined(WITH_CARET5)
RUN_DEPENDS+=   caret5:../../science/caret
.endif

.if defined(WITH_DTIQUERY)
RUN_DEPENDS+=   dtiquery:science/dtiquery
.endif

.if defined(WITH_FSL)
RUN_DEPENDS+=   fsl:../../science/fsl
.endif

.if defined(WITH_FREESURFER)
RUN_DEPENDS+=   ${LINUXBASE}${LOCALBASE}/freesurfer/bin/csurf:../../science/freesurfer
.endif

.if defined(WITH_SCILAB)
RUN_DEPENDS+=   scilab:math/scilab
.endif

.if ${OSVERSION} < 500000
IGNORE= many of the mritools ports do not run on FreeBSD < 5.0
.endif

post-patch:
	${CP} ${FILESDIR}/mritools.1 ${WRKDIR}
	${REINPLACE_CMD} -E "s|%%DEPENDS%%|${RUN_DEPENDS}|g" \
		${WRKDIR}/mritools.1
	${REINPLACE_CMD} -E "s| *[^ ]*\:/[^/ ]*/[^/ ]*/|, |g" \
		${WRKDIR}/mritools.1

do-install:
	@${MKDIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/mritools.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
