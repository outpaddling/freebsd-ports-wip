# New ports collection makefile for:	freecad
# Date created:		2010-02-27
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	freecad
PORTVERSION=	0.12.5284
CATEGORIES=	cad
MASTER_SITES:=	SF/free-cad/FreeCAD%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/FreeCAD-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Free 3D CAD modelling

# See Cmake output
# gl, python, boost, xerces-c, zlib, swig, eigen3, ode, qt, spnav
LIB_DEPENDS=	BinLPlugin:${PORTSDIR}/cad/opencascade \
		SoQt:${PORTSDIR}/x11-toolkits/soqt \
		xerces-c:${PORTSDIR}/textproc/xerces-c2
BUILD_DEPENDS=	${PREFIX}/lib/libsysinfo.a:${PORTSDIR}/devel/libsysinfo
#BUILD_DEPENDS=	ode-config:${PORTSDIR}/devel/ode

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
