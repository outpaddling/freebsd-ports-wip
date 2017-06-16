# New ports collection makefile for:	freecad
# Date created:		2010-02-27
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freecad
PORTVERSION=	0.12.5284
CATEGORIES=	wip cad
MASTER_SITES:=	SF/free-cad/FreeCAD%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/FreeCAD-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Free 3D CAD modelling

# See Cmake output
# gl, python, boost, xerces-c, zlib, swig, eigen3, ode, qt, spnav
LIB_DEPENDS=	BinLPlugin:cad/opencascade \
		SoQt:x11-toolkits/soqt \
		xerces-c:textproc/xerces-c2
BUILD_DEPENDS=	${PREFIX}/lib/libsysinfo.a:devel/libsysinfo
#BUILD_DEPENDS=	ode-config:devel/ode

CMAKE_ARGS+=	-DOCC_INCLUDE_DIR:PATH=${PREFIX}/include/opencascade \
		-DOCC_LIB_DIR:PATH=${PREFIX}/lib

# eigen2

# USE_AUTOTOOLS=	autoconf
USE_CMAKE=	yes
USE_FORTRAN=	yes

#CONFIGURE_ARGS=	--with-xercesc-lib=/usr/local/lib \
#		--with-boost-include=/usr/local/include \
#		--with-boost-lib=/usr/local/lib

#post-patch:
#	${REINPLACE_CMD} 's|-mt\"|\"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
