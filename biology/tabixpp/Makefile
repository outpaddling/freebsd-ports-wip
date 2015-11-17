# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	e75be649b38c8315d1fdc51c0a07e3765d66bb26
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ wrapper to tabix indexer

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib

USES=		tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

PLIST_FILES=	bin/tabix++ include/${PORTNAME}/tabix.hpp

CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	HTS_HEADERS='' LIBPATH=-L${LOCALBASE}/lib HTS_LIB=''

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/tabix++ ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tabix.hpp ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
