# Created by: Jason W. Bacon <bacon4000@gmail.com>
# $FreeBSD$

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
		${LOCALBASE}/mpi/openmpi/bin/mpiCC:${PORTSDIR}/net/openmpi \
		${LOCALBASE}/mpi/openmpi/lib/libscotch.a:/usr/wip/cad/scotch-openmpi
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi

USES=		bison gmake ncurses readline tar:tgz
# Requires gcc 4.5 or clang 3.6 according to docs
# wmake config files are hacked specifically for 4.8 at the moment
USE_GCC=	4.8
QT4_USE=	opengl webkit
USE_GL=		glut

# Ubuntu deps not accounted for:
# Need cmake only for Paraview
# libxt-dev qt4-dev-tools libqt4-dev freeglut3-dev

NO_CONFIGURE=	yes

MAKE_ENV=	SED=${SED}

# FIXME: Assuming AMD64 for now.  This should probably be made to work
# on i386 as well.
post-patch:
	@${REINPLACE_CMD} -e 's|"make"|"gmake"|g' \
		${WRKSRC}/wmake/wmake
	@${REINPLACE_CMD} -e 's|sed -i|sed -i.bak|g' \
		${WRKSRC}/bin/tools/foamConfigurePaths \
		${WRKSRC}/bin/tools/pre-commit-hook \
		${WRKSRC}/wmake/MakefileFiles \
		${WRKSRC}/tutorials/lagrangian/reactingParcelFilmFoam/hotBoxes/Allrun.pre
	@${REINPLACE_CMD} \
		-e 's|$$HOME/$$WM_PROJECT|${WRKDIR}|' \
		-e 's|WM_COMPILER=Gcc|WM_COMPILER=Gcc48|' \
		${WRKSRC}/etc/bashrc
	@${CP} -r ${FILESDIR}/FreeBSDGcc48 ${WRKSRC}/wmake/rules
	@${REINPLACE_CMD} \
		-e 's|-lscotch|-L${LOCALBASE}/mpi/openmpi/lib -lscotch|'g \
		${WRKSRC}/applications/utilities/parallelProcessing/decomposePar/Make/options \
		${WRKSRC}/applications/utilities/mesh/generation/foamyMesh/foamyHexMeshSurfaceSimplify/Make/options \
		${WRKSRC}/applications/utilities/mesh/generation/foamyMesh/foamyHexMeshBackgroundMesh/Make/options \
		${WRKSRC}/applications/utilities/mesh/manipulation/renumberMesh/Make/options \
		${WRKSRC}/src/parallel/decompose/scotchDecomp/Make/options \
		${WRKSRC}/src/parallel/decompose/ptscotchDecomp/Make/options \

do-build:
	(cd ${WRKSRC} && . etc/bashrc && ./Allwmake)

do-install:
	@echo TBD

.include <bsd.port.mk>
