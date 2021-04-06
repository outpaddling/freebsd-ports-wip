# Created by: Martin Tournoij <martin@arp242.net>

PORTNAME=	battray
DISTVERSIONPREFIX=	version-
DISTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	wip sysutils python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display notebook battery status in tray

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnome python:3.3+
USE_GNOME=	pygobject3
USE_PYTHON=	autoplist distutils optsuffix

USE_GITHUB=	yes
GH_ACCOUNT=	arp242
NO_ARCH=	yes

PLIST_FILES+=	etc/xdg/autostart/battray.desktop

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${FILESDIR}/battray.desktop \
		${STAGEDIR}${PREFIX}/etc/xdg/autostart

.include <bsd.port.mk>
