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
GH_TAGNAME=	20260724

SHEBANG_REGEX=	./(bin|wmake|tutorials)/.*

OPTIONS_DEFINE=	ZOLTAN
ZOLTAN_DESC=	Enable Zoltan decomposition support
ZOLTAN_LIB_DEPENDS=	libzoltan.so:science/trilinos

MAKE_ENV=	SCOTCH_TYPE=system \
		SCOTCH_ARCH_PATH=${LOCALBASE} \
		ZOLTAN_TYPE=system \
		ZOLTAN_ARCH_PATH=${LOCALBASE}

post-extract:
	@${LN} -sf ${WRKSRC} ${WRKDIR}/OpenFOAM-14
	@${CP} ${FILESDIR}/prefs.sh ${WRKSRC}/etc
	@${CP} -R ${FILESDIR}/FreeBSDClang ${WRKSRC}/wmake/rules
	
post-patch:
	@${REINPLACE_CMD} \
		's|^make="make"$$|make="$$MAKE"|' \
		${WRKSRC}/wmake/wmake

	@${REINPLACE_CMD} \
		's|        make -j |        $$MAKE -j |' \
		${WRKSRC}/wmake/wmakeCollect

	@${REINPLACE_CMD} \
		's|cd wmake/src && make|cd wmake/src \&\& $$MAKE|' \
		${WRKSRC}/Allwmake

	@${REINPLACE_CMD} \
		's|\[ "$$d" != Optional \] && \[ "$$d" != Make \]|[ "$$d" != Optional ] \&\& [ "$$d" != Make ] \&\& [ "$$d" != PVReaders ]|' \
		${WRKSRC}/wmake/wmake

post-patch-ZOLTAN-on:
	@${ECHO_CMD} 'export ZOLTAN_TYPE=system' >> ${WRKSRC}/etc/prefs.sh

post-patch-ZOLTAN-off:
	@${ECHO_CMD} 'export ZOLTAN_TYPE=none' >> ${WRKSRC}/etc/prefs.sh

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
