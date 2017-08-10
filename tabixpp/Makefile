# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	2015.11.23
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	C++ wrapper to tabix indexer

# Unspecified
LICENSE=	PD

LIB_DEPENDS=	libhts.so:biology/htslib

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	38607a5128b4e61828d4961f588e7a185bf396b7

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	HTS_HEADERS='' LIBPATH=-L${LOCALBASE}/lib HTS_LIB=''

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/tabix++ \
		include/tabix.hpp \
		lib/libtabix.a \
		lib/libtabix.so \
		lib/libtabix.so.1

post-install:
	${CP} ${STAGEDIR}${PREFIX}/lib/libtabix.so.1 \
		${STAGEDIR}${PREFIX}/lib/libtabix.so

.include <bsd.port.mk>
