PORTNAME=	io_lib
DISTVERSION=	1.15.1
CATEGORIES=	wip biology
# Github generated distfiles are incomplete, so use custom tarball
# Installs conflicting htscodecs files and unbundling is a nightmare
# MASTER_SITES=	https://github.com/jkbonfield/io_lib/releases/download/io_lib-1-15-1/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Code for reading and writing bioinformatics / DNA Sequence formats
WWW=		https://github.com/jkbonfield/io_lib

LICENSE=	BSD3CLAUSE
#LICENSE_FILE=	

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate \
		libcurl.so:ftp/curl \
		libhtscodecs.so:wip/htscodecs

USES=		autoreconf libtool
USE_GITHUB=	yes

GH_ACCOUNT=	jkbonfield

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
