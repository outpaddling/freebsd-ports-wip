# New ports collection makefile for:	visit
# Date created:		2010-12-29
# Whom:			Jason Bacon <jwb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	visit
PORTVERSION=	2.12.3
CATEGORIES=	wip graphics science math
MASTER_SITES=	http://portal.nersc.gov/project/visit/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	interactive parallel visualization and graphical analysis tool

# Unclear about this
LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyVTK>0:math/py-pyvtk
# FIXME: Be less specific if possible to avoid breakage on vtk upgrade
LIB_DEPENDS+=	libvtkFiltersTexture-6.2.so:math/vtk6

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USES=		cmake python
USE_QT4=	corelib qmake

# FindVisItQt4.cmake
CONFIGURE_ENV+=	VISIT_QT_BIN=${LOCALBASE}

# FIXME: Replace python2.7 with var
post-patch:
	${REINPLACE_CMD} \
		-e 's|site-packages/vtk|site-packages/pyvtk|g' \
		-e 's|python\*|python2.7|g' \
		work/visit2.12.3/src/CMake/FindVisItVTK.cmake

.include <bsd.port.mk>
