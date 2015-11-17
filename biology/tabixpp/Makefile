# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	ef377b497f130be3304c8dd16a02f04f70900fac
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ wrapper to tabix indexer

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib

USES=		tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	${PORTVERSION}

PLIST_FILES=	bin/tabix++ include/${PORTNAME}/tabix.hpp

CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	HTS_HEADERS='' LIBPATH=-L${LOCALBASE}/lib HTS_LIB=''

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/tabix++ ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tabix.hpp ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
