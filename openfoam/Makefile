# http://www.openfoam.org/download/git.php

PORTNAME=	openfoam
PORTVERSION=	2112
CATEGORIES=	wip science
MASTER_SITES=	https://dl.openfoam.com/source/v2112/
DISTNAME=	OpenFOAM-v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source computational fluid dynamics

LICENSE=	GPLv3

BUILD_DEPENDS=	flex>0:textproc/flex \
		cgal>0:math/cgal
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libscotch.so:cad/scotch
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		bison gmake ncurses readline shebangfix tar:tgz
QT4_USE=	opengl webkit
USE_GL=		glut

do-build:
	(cd ${WRKSRC} && . etc/bashrc && ./Allwmake)

.include <bsd.port.mk>
