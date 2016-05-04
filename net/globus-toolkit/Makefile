# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	globus_toolkit
PORTVERSION=	6.0.1453307864
CATEGORIES=	net
MASTER_SITES=	http://toolkit.globus.org/ftppub/gt6/installers/src/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open source software toolkit used for building grids

GNU_CONFIGURE=	yes

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libssl.so:security/openssl

USE_JAVA=	yes

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
