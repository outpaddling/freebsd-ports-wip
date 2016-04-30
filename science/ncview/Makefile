# New ports collection makefile for:	ncview
# Date created:		2013-02-26
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ncview
PORTVERSION=	2.1.2
CATEGORIES=	science graphics
MASTER_SITES=	ftp://cirrus.ucsd.edu/pub/ncview/

MAINTAINER=	bacon4000@gmail.com
COMMENT=

GNU_CONFIGURE=	yes

# Temporary hack to make port use same compiler as netcdf-ftn
# Otherwise, can't link to netcdf built with Fortran support
# USE_FORTRAN=	yes

# Netcdf 3 won't cut it.  Need nc-config.
LIB_DEPENDS+=	netcdf.7:science/netcdf4

PLIST_FILES=	bin/ncview

.include <bsd.port.mk>
