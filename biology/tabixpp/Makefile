# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	2015.11.16
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ wrapper to tabix indexer

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib

USES=		tar:xz

PLIST_FILES=	bin/tabix++ include/tabix.hpp

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/tabix++ ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tabix.hpp ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
