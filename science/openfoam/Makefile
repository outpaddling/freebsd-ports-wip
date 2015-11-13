# Created by: Jason W. Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	openfoam
PORTVERSION=	3.0.0
CATEGORIES=	science
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	../foam
DISTNAME=	OpenFOAM-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open source computational fluid dynamics

LICENSE=	GPLv3

BUILD_DEPENDS=	flex>=2.5.35:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/mpi/openmpi/bin/mpiCC:${PORTSDIR}/net/openmpi
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi

# Need cmake only for Paraview
USES=		bison gmake ncurses readline tar:tgz
QT4_USE=	opengl webkit
USE_GL=		glut

# Ubuntu deps not accounted for:
# libxt-dev qt4-dev-tools libqt4-dev freeglut3-dev

NO_CONFIGURE=	yes

MAKE_ENV=	SED=${SED}

# See etc/bashrc.  These have no effect here.  Why?
# MAKE_ENV=	FOAM_INST_DIR=${WRKDIR} WM_COMPILER=Clang

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$HOME/$$WM_PROJECT|${WRKDIR}|' \
		-e 's|WM_COMPILER=Gcc|WM_COMPILER=Clang|' \
		${WRKSRC}/etc/bashrc
	${CP} -r ${WRKSRC}/wmake/rules/linux64Clang \
		${WRKSRC}/wmake/rules/FreeBSDClang
	#find ${WRKSRC} -name Allwmake -exec \
	#	sed -i '' -e 's|#!/bin/sh|#!/usr/local/bin/bash|' '{}' \;

do-build:
	(cd ${WRKSRC} && . etc/bashrc && ./Allwmake)

.include <bsd.port.mk>
