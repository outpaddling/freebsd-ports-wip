############################################################################
############################################################################

PORTNAME=	caret
PORTVERSION=	5.61
CATEGORIES=	wip science biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/Caret/
DISTFILES=	caret_source.v${PORTVERSION}.zip \
		caret_distfiles.v${PORTVERSION}.zip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Computerized Anatomical Reconstruction and Editing Toolkit
WWW=		https://brainmap.wustl.edu/

LIB_DEPENDS=	minc.1:science/minc \
		netcdf.[1-4]:science/netcdf \
		vtkCommon.5:math/vtk5 \
		lapack.[3-4]:math/lapack \
		qwt.5:/usr/ports/x11-toolkits/qwt5
BUILD_DEPENDS=	cmake:devel/cmake \
		${LOCALBASE}/bin/qmake-qt4:devel/qmake4
RUN_DEPENDS=	mpeg_encode:multimedia/mpeg_encode \
		mpeg_play:multimedia/mpeg_play

CONFLICTS=	caret-5.[34]*

USE_QT_VER=	4

RESTRICTED=	Must register to download at http://brainmap.wustl.edu/resources/caretnew.html

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/caret_source
ALL_TARGET=	rebuild
MAKE_ENV=	QTDIR="${LOCALBASE}" \
		QMAKESPEC="${LOCALBASE}/share/qt4/mkspecs/freebsd-g++" \
		QWT_INC_DIR="${LOCALBASE}/include/qwt" \
		QWT_LIB_DIR="${LOCALBASE}/lib" \
		NETCDF_INC_DIR="${LOCALBASE}/include" \
		NETCDF_LIB_DIR="${LOCALBASE}/lib" \
		VTK_INC_DIR="${LOCALBASE}/include/vtk-5.0" \
		VTK_LIB_DIR="${LOCALBASE}/lib/vtk-5.0" \
		LOCALBASE="${LOCALBASE}"

OPTIONS=	FLAT_FLUID "Build flat_fluid (needs math/atlas, long build)" off

SUB_FILES=	pkg-message caret.cshrc caret.profile caret.1

PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		caret.1

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING) && \
    !exists(${DISTDIR}/${PORTNAME}_source.v${PORTVERSION}${EXTRACT_SUFX})
pre-everything::
	@${PRINTF} "\nPlease register at http://brainmap.wustl.edu/resources/caretnew.html in order to download the source code ${PORTNAME}_source.v${PORTVERSION}${EXTRACT_SUFX} and place it in ${DISTDIR}.\n\n" | ${FMT}
	@${FALSE}
.endif

pre-fetch:
.if !exists(${LOCALBASE}/lib/libvtkMPEG2Encode.so.5)
	@${PRINTF} "\n${LOCALBASE}/lib/libvtkMPEG2Encode.so.5 not found.\nYou must build math/vtk5 with the VTKMPEG2 option enabled.  Note that installing multimedia/vtkmpeg2encode *after* vtk5 is installed will not suffice.  The math/vtk5 must be compiled with the VTKMPEG2 option on to enable the mpeg2 encoder functionality.\n\nThe VTKMPEG2 option is off by default due to patent restrictions on MPEG2 code.  You are solely responsible for any royalties due resulting from your use of the patented MPEG2 code.\n\n" | ${FMT}
	@${FALSE}
.endif

.if defined(WITH_FLAT_FLUID)
LIB_DEPENDS+=	atlas.2:math/atlas

PLIST_FILES+=	bin/flat_fluid

post-patch:
	${REINPLACE_CMD} "s|-latlas|-latlas -lgfortran|" ${WRKSRC}/flat_fluid/Makefile.FreeBSD
	${REINPLACE_CMD} "s|Q_IMPORT_PLUGIN|//Q_IMPORT_PLUGIN|" ${WRKSRC}/caret/main.cxx
	${REINPLACE_CMD} "s|Q_IMPORT_PLUGIN|//Q_IMPORT_PLUGIN|" ${WRKSRC}/caret_command/main.cxx

post-build:
	(d=`ls -d /usr/local/lib/gcc*`; ${REINPLACE_CMD} "s|-L /usr/local/lib|-L${LOCALBASE}/lib -L$${d} -rpath $${d}|" ${WRKSRC}/flat_fluid/Makefile.FreeBSD)
	(cd ${WRKSRC}/flat_fluid; ${MAKE} -f Makefile.FreeBSD)
.endif

do-install:
	@${MKDIR} ${PREFIX}/bin ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/caret/caret5 ${PREFIX}/bin
.for f in command edit
	${INSTALL_PROGRAM} ${WRKSRC}/caret_${f}/caret_${f} ${PREFIX}/bin
.endfor
.if defined(WITH_FLAT_FLUID)
	${INSTALL_PROGRAM} ${WRKSRC}/flat_fluid/flat_fluid ${PREFIX}/bin
.endif
	(cd ${WRKDIR}/caret_distfiles && ${COPYTREE_SHARE} \* ${DATADIR})
	${LN} -s ${DATADIR}/caret_help ${DOCSDIR}
	@${MKDIR} ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/caret.cshrc ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/caret.profile ${PREFIX}/etc/mri
	${INSTALL_MAN} ${WRKDIR}/caret.1 ${PREFIX}/share/man/man1

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
