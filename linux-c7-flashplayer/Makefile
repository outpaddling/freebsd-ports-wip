# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD: head/www/linux-flashplayer/Makefile 477195 2018-08-14 18:54:27Z jkim $

PORTNAME=	flashplayer
PORTVERSION=	30.0.0.154
CATEGORIES=	wip www multimedia linux
MASTER_SITES=	https://fpdownload.macromedia.com/get/flashplayer/pdc/${PORTVERSION}/
PKGNAMEPREFIX=	linux-c7-
DISTFILES=	flash_player_npapi_linux.i386.tar.gz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USES=		cpe linux:c7 webplugin:linux
CPE_VENDOR=	adobe
CPE_PRODUCT=	flash_player
USE_LINUX=	alsalib alsa-plugins-oss curl dri gtk2 nspr nss
WEBPLUGIN_FILES=libflashplayer.so
# Defaults to linux-c7-flashplayer
WEBPLUGIN_DIR=	${PREFIX}/lib/browser_plugins/linux-flashplayer

RESTRICTED=	Redistribution not allowed

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=

post-patch:
	@${REINPLACE_CMD} '/^NotShowIn=KDE/d' \
		${WRKSRC}/usr/share/applications/flash-player-properties.desktop

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/libflashplayer.so ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/flash-player-properties ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/share/applications/flash-player-properties.desktop ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/usr/share/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>
