# $FreeBSD: head/www/flashplayer/Makefile 471958 2018-06-08 00:10:32Z jkim $

PORTNAME=	flashplayer
PORTVERSION=	30.0
CATEGORIES=	wip www multimedia
PKGNAMESUFFIX=	-c7
DISTFILES=

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Native wrapper around Linux Flash Player

RUN_DEPENDS=	${LOCALBASE}/lib/browser_plugins/linux-flashplayer/libflashplayer.so:wip/linux-c7-flashplayer \
		nspluginwrapper:wip/nspluginwrapper-c7

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

PLIST_FILES=	"@postexec ${LOCALBASE}/bin/nspluginwrapper -i ${LOCALBASE}/lib/browser_plugins/linux-flashplayer/libflashplayer.so" \
		"@rmtry lib/browser_plugins/npwrapper.libflashplayer.so"

.include <bsd.port.mk>
