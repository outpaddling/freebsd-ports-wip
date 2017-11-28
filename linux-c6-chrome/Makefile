# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD: head/devel/linux-c6-devtools/Makefile 373783 2014-12-02 21:02:33Z xmj $

PORTNAME=	chrome
PORTVERSION=	41
CATEGORIES=	wip www
DISTFILES=	google-chrome-stable_current_i386.rpm

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Linux Chrome closed-source browser

# https://www.google.com/chrome/browser/desktop/index.html?platform=linux
# LICENSE=	

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
USE_LINUX_APPS=	alsalib cups-libs dbuslibs avahi-libs gtk2
RUN_DEPENDS=	${LINUXBASE}/usr/bin/gconftool-2:wip/linux-c6-GConf2 \
		${LINUXBASE}/usr/lib/libORBit-2.so.0:wip/linux-c6-ORBit2

# USE_JAVA=       yes
# JAVA_VERSION=   1.6+
# JAVA_OS=        linux
# JAVA_RUN=       yes

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${LN} ${STAGEDIR}${PREFIX}/opt/google/chrome/chrome \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
