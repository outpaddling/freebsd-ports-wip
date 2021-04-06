############################################################################
############################################################################
# www.neuro.mcw.edu has the latest source distribution from which this port
# is built.  It will be updated as time permits and necessiaty requires.

PORTNAME=	bioimagesuite
PORTVERSION=	2.5
CATEGORIES=	wip science biology
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/bioimagesuite/${PORTVERSION}/ \
		http://www.bioimagesuite.org/download/src/
DISTFILES=	bioimagesuite_latest_FreeBSD_g++32.tar.gz \
		bioimagesuite_${PORTVERSION}_src_1166.zip \
		VTK_4.4.2_patched.zip
EXTRACT_ONLY=	bioimagesuite_extra_FreeBSD_g++32_Dec_2006.tar.gz \
		bioimagesuite_latest_FreeBSD_g++32.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	BioImageSuite
WRKSRC=		${WRKDIR}/bioimagesuite_src

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

#FETCH_ENV=      HTTP_AUTH="basic:anonymous:bioimagesuite"
BUILD_ENV=	BASE=${WRKSRC}/bioimagesuite

.include <bsd.port.pre.mk>

#.if !defined(PACKAGE_BUILDING) && \
#	(!exists(${DISTDIR}/bioimagesuite_latest_FreeBSD_g++32.tar.gz) || \
#	!exists(${DISTDIR}/bioimagesuite_extra_FreeBSD_g++32_Dec_2006.tar.gz) || \
#	!exists(${DISTDIR}/itk241_yale_FreeBSD_g++32.tar.gz) || \
#	!exists(${DISTDIR}/vtk44_yale_FreeBSD_g++32.tar.gz) )
#pre-everything::
#	@${PRINTF} "\nPlease register at http://bioimagesuite.org, download the files bioimagesuite_2.0RC2_FreeBSD_g++32.tar.gz, bioimagesuite_extra_FreeBSD_g++32_Dec_2006.tar.gz, itk241_yale_FreeBSD_g++32.tar.gz, and vtk44_yale_FreeBSD_g++32.tar.gz, and place them in ${DISTDIR}.\n\n" | ${FMT}
#	@${FALSE}
#.endif

post-extract:
	(cd ${WRKDIR} && ${UNZIP_CMD} -q ${DISTDIR}/bioimagesuite_2.0_src_1166.zip && ${UNZIP_CMD} -q ${DISTDIR}/VTK_4.4.2_patched.zip)
	${REINPLACE_CMD} -e 's|$${HOME}/src/bioimagesuite|${WRKSRC}/bioimagesuite|g' ${WRKSRC}/bioimagesuite/setpaths.sh
	${CP} ${WRKDIR}/bioimagesuite/lib/*Closed* ${WRKSRC}/bioimagesuite/lib

do-build:
	(cd ${WRKSRC}/build && ccmake ..)

do-install:
	${CP} -R ${WRKDIR}/* ${PREFIX}

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
