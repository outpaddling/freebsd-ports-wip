############################################################################
############################################################################
# www.neuro.mcw.edu has the latest source distribution from which this port
# is built.  It will be updated as time permits and necessiaty requires.

PORTNAME=	bioimagesuite
PORTVERSION=	2.0
CATEGORIES=	wip science biology
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/BioImageSuite/2.0RC2/
DISTFILES=	bioimagesuite_latest_FreeBSD_g++32.tar.gz \
		bioimagesuite_extra_FreeBSD_g++32_Dec_2006.tar.gz \
		itk241_yale_FreeBSD_g++32.tar.gz \
		vtk44_yale_FreeBSD_g++32.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	BioImageSuite

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_BUILD=	"YES"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	This binary does not run on FreeBSD < 5.0
.endif

.if !defined(PACKAGE_BUILDING) && \
	(!exists(${DISTDIR}/bioimagesuite_latest_FreeBSD_g++32.tar.gz) || \
	!exists(${DISTDIR}/bioimagesuite_extra_FreeBSD_g++32_Dec_2006.tar.gz) || \
	!exists(${DISTDIR}/itk241_yale_FreeBSD_g++32.tar.gz) || \
	!exists(${DISTDIR}/vtk44_yale_FreeBSD_g++32.tar.gz) )
pre-everything::
	@${PRINTF} "\nPlease register at http://bioimagesuite.org, download the files bioimagesuite_2.0RC2_FreeBSD_g++32.tar.gz, bioimagesuite_extra_FreeBSD_g++32_Dec_2006.tar.gz, itk241_yale_FreeBSD_g++32.tar.gz, and vtk44_yale_FreeBSD_g++32.tar.gz, and place them in ${DISTDIR}.\n\n" | ${FMT}
	@${FALSE}
.endif

post-extract:
	${CP} -f ${FILESDIR}/start_bioimagesuite ${WRKDIR}/bioimagesuite

do-install:
	${CP} -R ${WRKDIR}/* ${PREFIX}

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
