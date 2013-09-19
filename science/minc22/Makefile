# Created by: jbacon
# $FreeBSD: science/minc2/Makefile 325245 2013-08-22 23:55:13Z marino $

############################################################################
# http://www.bic.mni.mcgill.ca/software/minc/
# is the ultimate source for MINC, and will always contain the latest
# source release.  If this port is not up to date enough for you,
# you can download the latest sources and build manually.  On FreeBSD,
# you must configure with the environment variable LDFLAGS set to
# ${LOCALBASE}/lib so that the configure script will find libnetcdf.
# Of course, the netcdf port must be installed first.

PORTNAME=	minc
PORTVERSION=	2.2.00
PORTREVISION=	2
CATEGORIES=	science biology
MASTER_SITES=	http://packages.bic.mni.mcgill.ca/tgz/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Medical Imaging NetCDF

LICENSE=	BSD

LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf

# The hdf5 API changed after version 1.6.
# LIB_DEPENDS=hdf5 is satisfied by either science/hdf5 or science/hdf5-18,
# which can cause build failures in ports requiring hdf5 1.8 if hdf5 1.6
# is already installed.  Several ports that depend on hdf5 have this bug.
# LIB_DEPENDS=hdf5.7 will break the port when a minor hdf5 ugrade occurs.
# Below is a kludgey but reliable way to ensure that hdf5 > 1.6 is installed.
# The pkgsrc >= syntax would be a nice addition for this, e.g.
# LIB_DEPENDS=	hdf5>=1.8.0

BUILD_DEPENDS=	${LOCALBASE}/bin/h5copy:${PORTSDIR}/science/hdf5-18
RUN_DEPENDS=	${LOCALBASE}/bin/h5copy:${PORTSDIR}/science/hdf5-18

USE_LDCONFIG=	yes
USES=		cmake:outsource bison:build
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CMAKE_ARGS=	-DMINC2_BUILD_SHARED_LIBS:BOOL=YES

CONFLICTS=	minc-1* zh-tk-[0-9]*
LATEST_LINK=	minc2

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
