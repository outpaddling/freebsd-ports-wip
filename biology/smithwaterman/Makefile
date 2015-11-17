# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	smithwaterman
PORTVERSION=	2015.11.16
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Smith-waterman-gotoh alignment algorithm

USES=		gmake

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/include \
		${STAGEDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/smithwaterman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/*.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
