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

USES=		bison cmake ncurses readline tar:tgz
QT4_USE=	opengl webkit
USE_GL=		glut

# Ubuntu deps not accounted for:
# libxt-dev qt4-dev-tools libqt4-dev freeglut3-dev

do-build:
	cd ${WRKSRC} && ./Allwmake

.include <bsd.port.mk>
