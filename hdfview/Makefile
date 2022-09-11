PORTNAME=	hdfview
DISTVERSION=	3.1.3
CATEGORIES=	wip science
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/releases/HDF-JAVA/hdfview-3.1.3/src/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tool written in Java for browsing and editing HDF (HDF5 and HDF4) files
WWW=		https://portal.hdfgroup.org/display/HDFVIEW/HDFView#HDFView-install

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_JAVA=	yes

do-build:
	cd ${WRKSRC} && ant run

.include <bsd.port.mk>
