# New ports collection makefile for:	stm32flash
# Date created:		2011-06-15
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	stm32flash
PORTVERSION=	2011.05.30
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open source flash program for STM32 ARM processors using ST bootloader

.include <bsd.port.pre.mk>

USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|57600|115200|g' ${WRKSRC}/main.c
	${REINPLACE_CMD} -e 's|ttyS0|cuaU0|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
