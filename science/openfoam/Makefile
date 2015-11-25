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

BUILD_DEPENDS=	flex>=2.5.35:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/mpi/openmpi/bin/mpiCC:${PORTSDIR}/net/openmpi
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi

USES=		bison gmake ncurses readline tar:tgz
# Requires gcc 4.5 or clang 3.6 according to docs
USE_GCC=	yes
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
	${REINPLACE_CMD} \
		-e 's|$$HOME/$$WM_PROJECT|${WRKDIR}|' \
		-e 's|WM_COMPILER=Gcc|WM_COMPILER=Gcc48|' \
		${WRKSRC}/etc/bashrc
	${CP} -r ${WRKSRC}/wmake/rules/linux64Gcc \
		${WRKSRC}/wmake/rules/FreeBSDGcc48
	${REINPLACE_CMD} \
		-e 's|gcc|gcc48|g' \
		-e 's|-m64|-m64 -D_WITH_GETLINE|g' \
		${WRKSRC}/wmake/rules/FreeBSDGcc48/c
	${REINPLACE_CMD} \
		-e 's|g++|g++48|g' \
		-e 's|-m64|-m64 -D_WITH_GETLINE|g' \
		${WRKSRC}/wmake/rules/FreeBSDGcc48/c++

do-build:
	(cd ${WRKSRC} && . etc/bashrc && ./Allwmake)

.include <bsd.port.mk>
