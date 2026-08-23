PORTNAME=	openfoam
DISTVERSION=	14
CATEGORIES=	wip science

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
GH_TAGNAME=	d7a67142d6f8fc57ba1ed6be52e1016f446d0356

SHEBANG_REGEX=	./(bin|wmake|tutorials)/.*

NO_CONFIGURE=	yes
PATCH_STRIP=	-p1

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
	${LS} -ld ${WRKDIR}/OpenFOAM-14
	${TEST} -f ${WRKDIR}/OpenFOAM-14/etc/config.sh/functions

	cd ${WRKSRC} && \
		${SETENV} \
		MAKE=${GMAKE} \
		MAKEFLAGS= \
		${LOCALBASE}/bin/bash -c '\
			. ./etc/bashrc && \
			echo "OpenFOAM make: $$MAKE" && \
			$$MAKE --version | head -1 && \
			cd $$WM_PROJECT_DIR/wmake/src && $$MAKE && \
			cd $$WM_PROJECT_DIR/src/OSspecific/POSIX && wmake libso . && \
			cd $$WM_PROJECT_DIR/src/Pstream/dummy && wmake && \
			cd $$WM_PROJECT_DIR/src/OpenFOAM && wmake && \
			cd $$WM_PROJECT_DIR && ./Allwmake'

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/OpenFOAM-14

	${CP} -R \
		${WRKSRC}/bin \
		${STAGEDIR}${PREFIX}/OpenFOAM-14/

	${CP} -R \
		${WRKSRC}/etc \
		${STAGEDIR}${PREFIX}/OpenFOAM-14/

	${CP} -R \
		${WRKSRC}/wmake \
		${STAGEDIR}${PREFIX}/OpenFOAM-14/

	${CP} -R \
		${WRKSRC}/tutorials \
		${STAGEDIR}${PREFIX}/OpenFOAM-14/

	${MKDIR} \
		${STAGEDIR}${PREFIX}/OpenFOAM-14/platforms/freebsd64ClangDPInt32Opt

	${CP} -R \
		${WRKSRC}/platforms/freebsd64ClangDPInt32Opt/bin \
		${STAGEDIR}${PREFIX}/OpenFOAM-14/platforms/freebsd64ClangDPInt32Opt/

	${CP} -R \
		${WRKSRC}/platforms/freebsd64ClangDPInt32Opt/lib \
		${STAGEDIR}${PREFIX}/OpenFOAM-14/platforms/freebsd64ClangDPInt32Opt/

.include <bsd.port.mk>
