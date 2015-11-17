# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	smithwaterman
PORTVERSION=	ebfdcd14b3f8f0d37e3bf4c3282aa32d7c1399d2
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Smith-waterman-gotoh alignment algorithm

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

MAKE_ENV+=	OBJ=libsw.a

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/smithwaterman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
