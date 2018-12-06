#
# $FreeBSD$
#

PORTNAME=	visit
PORTVERSION=	2.13.1
CATEGORIES=	wip graphics science math
MASTER_SITES=	http://portal.nersc.gov/project/visit/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	interactive parallel visualization and graphical analysis tool

# Unclear about this
LICENSE=	BSD3CLAUSE

# QVTKWidget.h requires a non-default vtk option
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyVTK>0:math/py-pyvtk \
		${LOCALBASE}/include/vtk-6.2/QVTKWidget.h:math/vtk6
# FIXME: Be less specific if possible to avoid breakage on vtk upgrade
LIB_DEPENDS+=	libvtkFiltersExtraction-pv5.5.so:math/vtk6 \
		libqwt.so:x11-toolkits/qwt5

USES=		cmake:noninja python
USE_QT5=	qmake
# USE_GCC=	yes

# FindVisItQt4.cmake
CONFIGURE_ENV+=	VISIT_QT_BIN=${LOCALBASE}
CMAKE_ARGS+=	-DVISIT_QT_DIR:STRING=${LOCALBASE}/lib/qt5 \
		-DVISIT_QWT_DIR:STRING=${LOCALBASE} \
		-DVISIT_USE_GLEW:BOOL=off
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_JOBS_UNSAFE=	yes
# XOPEN_SOURCE:isascii() BSD_VISIBLE:gethostbyname()
CXXFLAGS+=	-D_XOPEN_SOURCE=700 -D__BSD_VISIBLE

# FIXME: Replace python2.7 with var
post-patch:
	${REINPLACE_CMD} \
		-e 's|site-packages/vtk|site-packages/pyvtk|g' \
		-e 's|python\*|${PYTHON_CMD}|g' \
		work/visit${PORTVERSION}/src/CMake/FindVisItVTK.cmake

.include <bsd.port.mk>
