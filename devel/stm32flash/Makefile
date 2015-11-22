# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	stm32flash
PORTVERSION=	2011.05.30
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
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
