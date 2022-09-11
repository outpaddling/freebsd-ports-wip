PORTNAME=	dlpoly
PORTVERSION=	1.10
CATEGORIES=	wip science java
PKGNAMESUFFIX=	classic
DISTNAME=	dl_class_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Molecular dynamics simulation package
WWW=		https://ccpforge.cse.rl.ac.uk/gf/project/dl_poly_classic/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.pdf

LIB_DEPENDS=	libmpi.so:net/openmpi3

USES=		fortran gmake
USE_GITLAB=	yes
GL_ACCOUNT=	DL_POLY_CLASSIC
GL_PROJECT=	dl_poly
GL_COMMIT=	565a1de4234430452c8248426ca2fa15d532334d

OPTIONS_DEFINE=		GUI DOCS EXAMPLES
OPTIONS_DEFAULT=	GUI
GUI_DESC=		Install Java GUI

SUB_FILES=	dlpoly-gui

BUILD_WRKSRC=	${WRKSRC}/source

MPIF90=		${LOCALBASE}/mpi/openmpi3/bin/mpif90

GUI_USE=		JAVA=yes
GUI_PLIST_FILES=	bin/dlpoly-gui \
			${DATADIR_REL}/GUI.jar

post-patch:
	${CP} ${WRKSRC}/build/MakePAR ${WRKSRC}/build/MakeSEQ ${BUILD_WRKSRC}
	${REINPLACE_CMD} 's|gfortran|${FC}|g' ${BUILD_WRKSRC}/MakeSEQ
	${REINPLACE_CMD} 's|DLPOLY\.X|dlpoly-classic|g' ${BUILD_WRKSRC}/MakeSEQ
	${REINPLACE_CMD} 's|mpif90|${MPIF90}|g' \
		${BUILD_WRKSRC}/MakePAR
	${REINPLACE_CMD} 's|DLPOLY\.X|dlpoly-classic-mpi|g' \
		${BUILD_WRKSRC}/MakePAR

do-build:
	(cd ${BUILD_WRKSRC} && \
		${CP} -f MakeSEQ Makefile && \
		${MAKE} ${FC})
	(cd ${BUILD_WRKSRC} && \
		${MAKE} clean && \
		${CP} -f MakePAR Makefile && \
		${MAKE} gfortran)

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic-mpi ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/execute ${STAGEDIR}${EXAMPLESDIR}
	${RM} ${STAGEDIR}${EXAMPLESDIR}/execute/dlpoly*
.if ${PORT_OPTIONS:MGUI}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/java/GUI.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/dlpoly-gui ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
