# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD: head/devel/linux-c6-devtools/Makefile 373783 2014-12-02 21:02:33Z xmj $

PORTNAME=	chrome
PORTVERSION=	41
CATEGORIES=	www
DISTFILES=	google-chrome-stable_current_i386.rpm

MAINTAINER=	jwbacon@tds.net
COMMENT=	Linux Chrome closed-source browser

# https://www.google.com/chrome/browser/desktop/index.html?platform=linux
# LICENSE=	Various GNU

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

PLIST_SUB+=	NLS=""

# Depends: linux-c6-gconf

.include <bsd.port.mk>
