# $FreeBSD: head/science/afni/Makefile 427397 2016-11-29 21:15:41Z jrm $

############################################################################
# http://www.neuro.mcw.edu/Ports has the latest source distribution from
#  which this port is built.  It will be updated as time permits.
#
# afni.nimh.nih.gov is the ultimate source for AFNI, and will always
# contain the latest source release.  If this port is not up to date,
# you can download the latest sources and build manually.

PORTNAME=	afni
DISTVERSIONPREFIX=	AFNI_
DISTVERSION=	19.1.08
CATEGORIES=	wip science biology graphics

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Advanced Functional Neuro Imaging

LICENSE=	GPLv2

BUILD_DEPENDS=	gm4:devel/m4 \
		R:math/R
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libf2c.so:lang/f2c \
		libgsl.so:math/gsl \
		libnetcdff.so:science/netcdf-fortran \
		libxml2.so:textproc/libxml2 \
		libXm.so:x11-toolkits/open-motif
RUN_DEPENDS=	endian:sysutils/endian \
		mpeg_encode:multimedia/mpeg_encode \
		ppmtogif:graphics/netpbm \
		qhull:math/qhull5 \
		R:math/R

CONFLICTS=	im-[0-9]* \
		nifticlib-[0-9]* \
		open-usp-tukubai-[0-9]*

USES=		gettext gl gmake gnome iconv jpeg:run motif perl5 python shebangfix tar:xz
SHEBANG_FILES=	scripts_install/3dPAR2AFNI.pl \
		python_scripts/afni_python/*.py
USE_GNOME=	glib20
USE_GITHUB=	yes

.include <bsd.port.options.mk>

BROKEN_sparc64=	Does not compile: "undefined reference to '_mcount'"

USE_GL=		gl glu glw
USE_XORG=	x11 xext xi xmu xp xt
MAKE_ENV=	CC="${CC}" R_SHARE_DIR=${LOCALBASE}/lib/R/share
MAKE_JOBS_UNSAFE=yes

WRKSRC_SUBDIR=	src
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
.for f in ${X11R6_FILES}
	@${REINPLACE_CMD} \
		-e 's|/usr/X11R6|$${LOCALBASE}|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} \
		-E 's|AFNI_[0-9_]+|${PORTVERSION}|g' ${WRKSRC}/AFNI_label.h
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${RM} ${WRKSRC}/3DEdge/src/Makefile.orig

# shebangfix misses /bin/python on 10.1
pre-configure:
	${REINPLACE_CMD} -e "s|-lglib|-lglib-2.0|g" \
		${WRKSRC}/SUMA/SUMA_Makefile
	${REINPLACE_CMD} -e "s|/bin/python|${PYTHON_CMD}|g" \
		${WRKSRC}/python_scripts/afni_python/lib_fat_Rfactor.py
	${REINPLACE_CMD} \
		-e 's|os\.path\.dirname(sys\.argv\[0\])|"${PREFIX}/libexec"|g' \
		${WRKSRC}/pkundu/meica.py
	${REINPLACE_CMD} \
		-e 's|g_info|afni_g_info|g' \
		${WRKSRC}/rickr/Dimon.c \
		${WRKSRC}/rickr/Dimon1.c \
		${WRKSRC}/afni_history_rickr.c \
		${WRKSRC}/mri_dicom_stuff.c \
		${WRKSRC}/mri_process_siemens.c \
		${WRKSRC}/mri_read_dicom.c \
		${WRKSRC}/to3d.c \
		${WRKSRC}/mri_dicom_stuff.h

do-install:
	# AFNI just dumps everything into one flat directory
	# Preserve original install dir and make a copy to pick apart
	${RM} -r ${INSTALL_WRKSRC}-temp
	${CP} -R ${INSTALL_WRKSRC} ${INSTALL_WRKSRC}-temp

	# Clean up and organize files into ${PRESTAGE}, destroying
	# temp dir in the process
	${RM} -rf ${PRESTAGE}
	@${MKDIR} ${PRESTAGE}/bin \
		${PRESTAGE}/scripts \
		${PRESTAGE}/lib \
		${PRESTAGE}/include \
		${PRESTAGE}/trash \
		${PRESTAGE}/doc \
		${PRESTAGE}/share
	${RM}	${INSTALL_WRKSRC}-temp/libf2c.a
	${MV}	${INSTALL_WRKSRC}-temp/*.a \
		${INSTALL_WRKSRC}-temp/*.so \
		${PRESTAGE}/lib
	${MV}	${INSTALL_WRKSRC}-temp/funstuff \
		${INSTALL_WRKSRC}-temp/AFNI.*rc \
		${INSTALL_WRKSRC}-temp/afnigui* \
		${PRESTAGE}/share
	${MV}	${INSTALL_WRKSRC}-temp/*.h ${PRESTAGE}/include
	${CP}	${WRKDIR}/afni-AFNI_${PORTVERSION}/doc/README* ${PRESTAGE}/doc
	for binary in `${FILE} ${INSTALL_WRKSRC}-temp/* | fgrep 'ELF' | ${AWK} -F ':' ' { print $$1 }'` ; do \
		${MV} $${binary} ${PRESTAGE}/bin ; \
	done
	${MV}	${INSTALL_WRKSRC}-temp/* ${PRESTAGE}/scripts
	${MV}	${PRESTAGE}/scripts/meica.libs ${PRESTAGE}
	${MV}	${PRESTAGE}/scripts/lib_RetroTS ${PRESTAGE}
	${MV}	${PRESTAGE}/scripts/shiny ${PRESTAGE}

	# Proper installation to destdir
	@${MKDIR} ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PREFIX}/lib/afni \
		${STAGEDIR}${PREFIX}/include/afni
	for f in ${PRESTAGE}/lib/*; do \
		${STRIP_CMD} $${f}; \
	done
	${INSTALL_DATA} ${PRESTAGE}/lib/* ${STAGEDIR}${PREFIX}/lib/afni
	${INSTALL_DATA} ${PRESTAGE}/include/* ${STAGEDIR}${PREFIX}/include/afni
	cd ${PRESTAGE}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${PRESTAGE}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${PRESTAGE}/scripts/* ${STAGEDIR}${PREFIX}/bin
	cd ${PRESTAGE} && ${COPYTREE_BIN} meica.libs lib_RetroTS shiny \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/Atlases/* ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/afni.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${PREFIX}/etc/mri
	${INSTALL_DATA} ${PRESTAGE}/doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/afni.cshrc ${WRKDIR}/afni.profile \
		${STAGEDIR}${PREFIX}/etc/mri

.include <bsd.port.mk>
