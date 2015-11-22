# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	3ef7baaac1df3b91ebd2571b89f5c391ef41519d
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	C++ wrapper to tabix indexer

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib

USES=		tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

PLIST_FILES=	bin/tabix++ include/tabix.hpp lib/libtabix.a lib/libtabix.so

CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	HTS_HEADERS='' LIBPATH=-L${LOCALBASE}/lib HTS_LIB=''

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
