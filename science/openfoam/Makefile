# Created by: Jason W. Bacon <bacon4000@gmail.com>
# $FreeBSD$
# http://www.openfoam.org/download/git.php

PORTNAME=	openfoam
PORTVERSION=	3.0.0
CATEGORIES=	science
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	../foam
DISTNAME=	OpenFOAM-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open source computational fluid dynamics

LICENSE=	GPLv3

# Does not build with flex 2.6.0
BUILD_DEPENDS=	flex<=2.5.39_2:/usr/wip/textproc/flex \
		${LOCALBASE}/mpi/openmpi/bin/mpiCC:net/openmpi \
		${LOCALBASE}/mpi/openmpi/lib/libscotch.a:/usr/wip/cad/scotch-openmpi
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
RUN_DEPENDS=	gnuplot:math/gnuplot \
		${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi

USES=		bison gmake ncurses readline shebangfix tar:tgz
# Requires gcc 4.5 or clang 3.6 according to docs
# wmake config files are hacked specifically for 4.8 at the moment
USE_GCC=	4.8
QT4_USE=	opengl webkit
USE_GL=		glut
SHEBANG_FILES=	${WRKSRC}/wmake/wmakeSchedulerUptime \
		${WRKSRC}/wmake/wmakeScheduler \
		${WRKSRC}/bin/tools/pre-receive-hook \
		${WRKSRC}/bin/tools/pre-commit-hook \
		${WRKSRC}/bin/tools/doxyFilter \
		${WRKSRC}/bin/foamExec \
		${WRKSRC}/doc/tools/find-trailingspace

# This should probably be made to work on at least i386 as well
# with a few additional changes.
ONLY_FOR_ARCHS=	amd64

# Ubuntu deps not accounted for:
# Need cmake only for Paraview
# libxt-dev qt4-dev-tools libqt4-dev freeglut3-dev

INSTALL_DIR=	${PREFIX}/${DISTNAME}
PLATFORM=	platforms/FreeBSDGcc48DPInt32Opt
USE_LDCONFIG=	${INSTALL_DIR}/${PLATFORM}/lib \
		${INSTALL_DIR}/${PLATFORM}/lib/dummy

post-patch:
	@${REINPLACE_CMD} -e 's|"make"|"gmake"|g' \
		${WRKSRC}/wmake/wmake
	@${REINPLACE_CMD} -e 's|sed -i|sed -i.bak|g' \
		${WRKSRC}/bin/tools/foamConfigurePaths \
		${WRKSRC}/bin/tools/pre-commit-hook \
		${WRKSRC}/wmake/MakefileFiles \
		${WRKSRC}/tutorials/lagrangian/reactingParcelFilmFoam/hotBoxes/Allrun.pre
	@${REINPLACE_CMD} \
		-e 's|foamInstall.*=.*$$HOME/$$WM_PROJECT|foamInstall=${WRKDIR}|' \
		-e 's|WM_COMPILER[ =]Gcc|&48|' \
		-e 's|$$WM_PROJECT_INST_DIR/ThirdParty-$$WM_PROJECT_VERSION|$$WM_PROJECT_DIR/ThirdParty|g' \
		${WRKSRC}/etc/bashrc \
		${WRKSRC}/etc/cshrc
	@${CP} -r ${FILESDIR}/FreeBSDGcc48 ${WRKSRC}/wmake/rules
	@${REINPLACE_CMD} \
		-e 's|-lscotch|-L${LOCALBASE}/mpi/openmpi/lib -lscotch|'g \
		${WRKSRC}/applications/utilities/parallelProcessing/decomposePar/Make/options \
		${WRKSRC}/applications/utilities/mesh/generation/foamyMesh/foamyHexMeshSurfaceSimplify/Make/options \
		${WRKSRC}/applications/utilities/mesh/generation/foamyMesh/foamyHexMeshBackgroundMesh/Make/options \
		${WRKSRC}/applications/utilities/mesh/manipulation/renumberMesh/Make/options \
		${WRKSRC}/src/parallel/decompose/scotchDecomp/Make/options \
		${WRKSRC}/src/parallel/decompose/ptscotchDecomp/Make/options
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/doc/Doxygen/Doxyfile
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/bin/mpirunDebug

do-build:
	(cd ${WRKSRC} && . etc/bashrc && ./Allwmake)

# Loosely based on content of the official Debian package.
do-install:
	${MKDIR} \
		${STAGEDIR}${INSTALL_DIR}/${PLATFORM} \
		${STAGEDIR}${INSTALL_DIR}/ThirdParty
	${CP} -R \
		${WRKSRC}/applications \
		${WRKSRC}/bin \
		${WRKSRC}/etc \
		${STAGEDIR}${INSTALL_DIR}
	${CP} -R \
		${WRKSRC}/${PLATFORM}/bin \
		${WRKSRC}/${PLATFORM}/lib \
		${STAGEDIR}${INSTALL_DIR}/${PLATFORM}
	${CHMOD} -R a+rX ${STAGEDIR}${INSTALL_DIR}

# Same bashrc and cshrc used to set up the build path are sourced by users.
# OpenFOAM developers confirmed that installation is relocatable and only
# these files should need to be altered.
post-stage:
	@${REINPLACE_CMD} \
		-e 's|${WRKDIR}|${PREFIX}|g' \
		${STAGEDIR}${INSTALL_DIR}/etc/bashrc \
		${STAGEDIR}${INSTALL_DIR}/etc/cshrc

.include <bsd.port.mk>
