# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	multichoose
PORTVERSION=	9d52eb40bcfca1bcc92d933c925410d6300b2f10
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=

USES=		shebangfix
SHEBANG_FILES=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

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
