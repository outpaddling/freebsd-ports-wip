# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	38607a5128b4e61828d4961f588e7a185bf396b7
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	C++ wrapper to tabix indexer

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib

USES=		tar:xz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

PLIST_FILES=	bin/tabix++ include/tabix.hpp lib/libtabix.a lib/libtabix.so.1

CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	HTS_HEADERS='' LIBPATH=-L${LOCALBASE}/lib HTS_LIB=''

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
