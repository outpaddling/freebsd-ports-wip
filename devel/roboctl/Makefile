# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: ports/devel/roboctl/Makefile,v 1.9 2010/03/28 06:33:38 dinoex Exp $

PORTNAME=	roboctl
PORTVERSION=	0.3.8
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	API and tools for communicating with Lego and Vex robots

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libgamepad.a:${PORTSDIR}/devel/libgamepad

MAKE_ENV=	EXTRALIBS=-lbluetooth
MAKE_JOBS_UNSAFE=	yes

USES=		tar:xz

OPTIONS=	CUTECOM "Install cutecom for Vex debugging" Off

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.options.mk>

.if defined(WITH_CUTECOM)
RUN_DEPENDS+=	cutecom:${PORTSDIR}/comms/cutecom
.endif

pre-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} depend)

post-install:
	(cd ${WRKSRC}/Commands/NXTRemote; ${MAKE})
	${INSTALL_PROGRAM} ${WRKSRC}/Commands/NXTRemote/nxtremote ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/lego_bluetooth_config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Commands/NXTRemote/nxtremote.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
