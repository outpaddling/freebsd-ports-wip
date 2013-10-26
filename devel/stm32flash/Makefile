# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	stm32flash
PORTVERSION=	2011.05.30
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open source flash program for STM32 ARM processors using ST bootloader

USES=		gmake

.include <bsd.port.pre.mk>

USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|57600|115200|g' ${WRKSRC}/main.c
	${REINPLACE_CMD} -e 's|ttyS0|cuaU0|g' ${WRKSRC}/main.c
	${RM} ${WRKSRC}/parsers/parsers.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
