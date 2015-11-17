# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	multichoose
PORTVERSION=	2015.11.16
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=

USES=		shebangfix
SHEBANG_FILES=	*.py

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_PROGRAM} \
		${WRKSRC}/multichoose \
		${WRKSRC}/multipermute \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/*.py \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
