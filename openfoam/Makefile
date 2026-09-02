PORTNAME=	openfoam
DISTVERSION=	14.20260724
CATEGORIES=	science

MAINTAINER=	res2500@ukr.net
COMMENT=	Open source computational fluid dynamics toolbox
WWW=		https://openfoam.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		flex:textproc/flex

LIB_DEPENDS=	libmpi.so:net/mpich \
		libscotch.so:cad/scotch

USES=		compiler:c++14-lang gmake shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	OpenFOAM
GH_PROJECT=	OpenFOAM-14
GH_TAGNAME=	20260724

SHEBANG_REGEX=	./(bin|wmake|tutorials)/.*

NO_CONFIGURE=	yes
PATCH_STRIP=	-p1

OPENFOAM_HOME=	${PREFIX}/OpenFOAM-14

OPTIONS_DEFINE=	ZOLTAN

ZOLTAN_DESC=	Enable Zoltan decomposition support
ZOLTAN_LIB_DEPENDS=	libzoltan.so:science/trilinos

post-patch:
	${RM} -rf ${WRKDIR}/OpenFOAM-14
	${LN} -s ${WRKSRC} ${WRKDIR}/OpenFOAM-14

	${ECHO_CMD} 'export WM_COMPILER=Clang' > ${WRKSRC}/etc/prefs.sh
	${ECHO_CMD} 'export WM_MPLIB=SYSTEMMPI' >> ${WRKSRC}/etc/prefs.sh
	${ECHO_CMD} 'export MPI_ROOT=${LOCALBASE}' >> ${WRKSRC}/etc/prefs.sh
	${ECHO_CMD} 'export MPI_ARCH_FLAGS="-DMPICH_SKIP_MPICXX"' >> ${WRKSRC}/etc/prefs.sh
	${ECHO_CMD} 'export MPI_ARCH_INC="-isystem ${LOCALBASE}/include"' >> ${WRKSRC}/etc/prefs.sh
	${ECHO_CMD} 'export MPI_ARCH_LIBS="-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib -lmpi"' >> ${WRKSRC}/etc/prefs.sh
	${ECHO_CMD} 'export SCOTCH_TYPE=system' >> ${WRKSRC}/etc/prefs.sh

	${REINPLACE_CMD} \
		's|^make="make"$$|make="$$MAKE"|' \
		${WRKSRC}/wmake/wmake

	${REINPLACE_CMD} \
		's|        make -j |        $$MAKE -j |' \
		${WRKSRC}/wmake/wmakeCollect

	${REINPLACE_CMD} \
		's|cd wmake/src && make|cd wmake/src \&\& $$MAKE|' \
		${WRKSRC}/Allwmake

	${REINPLACE_CMD} \
		's|\[ "$$d" != Optional \] && \[ "$$d" != Make \]|[ "$$d" != Optional ] \&\& [ "$$d" != Make ] \&\& [ "$$d" != PVReaders ]|' \
		${WRKSRC}/wmake/wmake


post-patch-ZOLTAN-on:
	${ECHO_CMD} 'export ZOLTAN_TYPE=system' >> ${WRKSRC}/etc/prefs.sh

post-patch-ZOLTAN-off:
	${ECHO_CMD} 'export ZOLTAN_TYPE=none' >> ${WRKSRC}/etc/prefs.sh

do-build:
	cd ${WRKSRC} && \
		${SETENV} \
		MAKE=${GMAKE} \
		MAKEFLAGS= \
		WM_NCOMPPROCS=${MAKE_JOBS_NUMBER} \
		${LOCALBASE}/bin/bash -c '\
			. ./etc/bashrc && \
			cd $$WM_PROJECT_DIR/wmake/src && \
			$$MAKE && \
			cd $$WM_PROJECT_DIR/src/OSspecific/POSIX && \
			wmake libso . && \
			cd $$WM_PROJECT_DIR && \
			./Allwmake -j${MAKE_JOBS_NUMBER}'

do-install:
	${MKDIR} ${STAGEDIR}${OPENFOAM_HOME}

	(cd ${WRKSRC} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${OPENFOAM_HOME})

	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} etc ${STAGEDIR}${OPENFOAM_HOME})

	(cd ${WRKSRC} && \
		${COPYTREE_BIN} wmake ${STAGEDIR}${OPENFOAM_HOME})

	${MKDIR} \
		${STAGEDIR}${OPENFOAM_HOME}/platforms/freebsd64ClangDPInt32Opt

	(cd ${WRKSRC}/platforms/freebsd64ClangDPInt32Opt && \
		${COPYTREE_BIN} bin \
		${STAGEDIR}${OPENFOAM_HOME}/platforms/freebsd64ClangDPInt32Opt)

	(cd ${WRKSRC}/platforms/freebsd64ClangDPInt32Opt && \
		${COPYTREE_SHARE} lib \
		${STAGEDIR}${OPENFOAM_HOME}/platforms/freebsd64ClangDPInt32Opt)

	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} tutorials ${STAGEDIR}${OPENFOAM_HOME})

.include <bsd.port.mk>
