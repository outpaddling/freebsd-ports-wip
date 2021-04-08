PORTNAME=	stm32flash
PORTVERSION=	0.5
CATEGORIES=	wip devel
MASTER_SITES=	SF/stm32flash/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source flash program for STM32 ARM processors using ST bootloader

USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

# Defaults for Vex Cortex
post-patch:
	${REINPLACE_CMD} -e 's|57600|115200|g' ${WRKSRC}/main.c
	${REINPLACE_CMD} -e 's|ttyS0|cuaU0|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
