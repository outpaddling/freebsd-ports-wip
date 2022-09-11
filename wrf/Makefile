PORTNAME=	wrf
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.3
CATEGORIES=	wip science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Weather forecasting model
WWW=		https://www2.mmm.ucar.edu/wrf

LICENSE=	PD

LIB_DEPENDS=	libnetcdff.so:science/netcdf-fortran

USE_GITHUB=	yes
GH_ACCOUNT=	wrf-model
GH_PROJECT=	WRF

USES=		fortran

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	NETCDF=${LOCALBASE}

.include <bsd.port.mk>
