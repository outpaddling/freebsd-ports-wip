############################################################################

############################################################################
# www.neuro.mcw.edu has the latest source distribution from which this port
# is built.  It will be updated as time permits and necessiaty requires.

PORTNAME=	fsl
PORTVERSION=	4.1.1
CATEGORIES=	wip science biology
MASTER_SITES=	http://www.fmrib.ox.ac.uk/fsldownloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-sources

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	FMRIB Software Library
WWW=		https://www.fmrib.ox.ac.uk/fsl/

LIB_DEPENDS=	png.5:graphics/png \
		gd.4:graphics/gd \
		boost_regex.[34]:devel/boost-libs \
		fftw3.4:math/fftw3
RUN_DEPENDS=	gnuplot:math/gnuplot \
		convert:graphics/ImageMagick \
		tixwish:x11-toolkits/tix \
		bash:shells/bash \
		whirlgif:graphics/whirlgif
BUILD_DEPENDS=	tclsh8.4:lang/tcl84 \
		ginstall:sysutils/coreutils

OPTIONS=	FSLVIEW "Build fslview (Requires cmake,qt,qwt,vtk)" on

USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_FSLVIEW)
LIB_DEPENDS+=	qwt4.4:/usr/ports/x11-toolkits/qwt4 \
		vtkCommon.5:math/vtk5
BUILD_DEPENDS+=	qt>=3.3.6:x11-toolkits/qt33 \
		cmake>=2.2.3:devel/cmake
.endif

CONFLICTS=	fsl-3.3.* fsl-4.0.[012456789]*

RESTRICTED=	Must register to download at ${MASTER_SITES}

SUB_FILES=	pkg-message fsl.cshrc fsl.profile
PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(WITH_FSLVIEW)
PLIST_FILES+=	bin/fslview
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	you must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${MASTER_SITES}, place it in ${DISTDIR}, and then run make again.  Note that the FSL downloads page only provides the latest FSL version.  Users are advised to save a copy ${DISTNAME}${EXTRACT_SUFX} in case reinstallation is necessary at a later date.
.endif

WRKSRC=		${WRKDIR}/fsl

MAN1=		fsl.1

# fslmachtype.sh requires a patch before being used in the build process,
# so don't try to run it under post-extract.
post-patch:
	@${MKDIR} ${WRKSRC}/config/`${WRKSRC}/etc/fslconf/fslmachtype.sh`
	${CP} ${FILESDIR}/*.mk \
		${WRKSRC}/config/`${WRKSRC}/etc/fslconf/fslmachtype.sh`
	${REINPLACE_CMD} 's/-lqwt/-lqwt4/g' ${WRKSRC}/src/fslview/src/fslview/fslview.pro
	${REINPLACE_CMD} 's/qwt/qwt4/g' ${WRKSRC}/src/fslview/src/fslview/CMakeLists.txt

# FIXME:
# -I${WRKSRC}/extras/src/libprob is a hack around an apparent bug in cmake 2.6
# that messes up the include path for miscmaths.
# -DCMAKE_CXX_FLAGS="-I${WRKSRC}/extras/src/libprob -I${LOCALBASE}/include -I${LOCALBASE}/include/vtk-5.0 -I${LOCALBASE}/include/qwt4" \
do-build:
	(cd ${WRKSRC} && ./build)
.if defined(WITH_FSLVIEW)
	@${MKDIR} ${WRKDIR}/fslview-release
	(cd ${WRKDIR}/fslview-release && \
	cmake ../fsl/src/fslview \
		-DCMAKE_INSTALL_PREFIX=${LOCALBASE} \
		-DVTK_DIR=${LOCALBASE}/lib/vtk-5.0 \
		-DBOOST_DIR=${LOCALBASE}/include \
		-DQT_MOC_EXECUTABLE=${LOCALBASE}/bin/moc \
		-DQT_UIC_EXECUTABLE=${LOCALBASE}/bin/uic \
		-DQWT_DIR=${LOCALBASE} \
		-DDESIRED_QT_VERSION=3 \
		-DFSL_DIR=../fsl \
		-DCMAKE_CXX_FLAGS="-I${WRKSRC}/extras/src/libprob -I${LOCALBASE}/include -I${LOCALBASE}/include/vtk-5.0 -I${LOCALBASE}/include/qwt4" \
		-DCMAKE_VERBOSE_MAKEFILE="ON" \
		-DCMAKE_EXE_LINKER_FLAGS="-L../../../fsl/extras/lib -L../../../fsl/lib" \
	&& make)
.endif

# Do not use .if !defined(NOPORTDOCS).  FSL will not run without some of
# the image files stored in the docs dir.  These files must be found under
# $FSLDIR ($DATADIR for the port), so we create links to the docs there.
do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} etc ${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_BIN} tcl ${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	@${ECHO_CMD} "Installing doc..."
	(cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${DOCSDIR})
	@${ECHO_CMD} "Installing drefoc..."
	(cd ${WRKSRC} && ${COPYTREE_SHARE} refdoc ${DOCSDIR})
	@${RM} -f ${WRKSRC}/bin/whirlgif
	@${ECHO_CMD} "Stripping binaries..."
	${STRIP_CMD} `file -F ' ' ${WRKSRC}/bin/* | \
		fgrep ELF | ${AWK} ' { print $$1 }'`
	@${ECHO_CMD} "Installing programs..."
	(cd ${WRKSRC} && ${COPYTREE_BIN} bin ${PREFIX})

	${LN} -s ${DOCSDIR}/* ${DATADIR}
	${LN} -s ${PREFIX}/bin ${DATADIR}
.if defined(WITH_FSLVIEW)
	${INSTALL_PROGRAM} ${WRKDIR}/fslview-release/bin/fslview ${PREFIX}/bin
.endif
	${INSTALL_MAN} ${FILESDIR}/fsl.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/fsl.cshrc ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/fsl.profile ${PREFIX}/etc/mri

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
