PORTNAME=	wgrib2
PORTVERSION=	2.0.7
CATEGORIES=	wip science
MASTER_SITES=	http://www.ftp.cpc.ncep.noaa.gov/wd51we/wgrib2/
# Maybe use nolib dist and unbundle netcdf, etc.
DISTFILES=	${PORTNAME}.tgz.v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for managing GRIB weather data files
WWW=		https://www.cpc.noaa.gov/products/wesley/wgrib2/

LICENSE=	GPLv2

USES=		gmake fortran

WRKSRC=		${WRKDIR}/grib2
MAKEFILE=	makefile
MAKE_ENV=	COMP_SYS=clang_linux
PLIST_FILES=	bin/wgrib2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wgrib2/wgrib2 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
