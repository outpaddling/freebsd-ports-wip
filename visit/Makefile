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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyVTK>0:math/py-pyvtk
# FIXME: Be less specific if possible to avoid breakage on vtk upgrade
LIB_DEPENDS+=	libvtkFiltersTexture-6.2.so:math/vtk6 \
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
# MAKE_JOBS_UNSAFE=	yes

# FIXME: Replace python2.7 with var
post-patch:
	${REINPLACE_CMD} \
		-e 's|site-packages/vtk|site-packages/pyvtk|g' \
		-e 's|python\*|${PYTHON_CMD}|g' \
		work/visit${PORTVERSION}/src/CMake/FindVisItVTK.cmake

.include <bsd.port.mk>
