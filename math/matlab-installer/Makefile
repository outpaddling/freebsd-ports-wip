# Created by:	Jason Bacon <jwbacon@tds.net>
# $FreeBSD: math/matlab-R2012a-installer/Makefile 327746 2013-09-20 20:55:04Z bapt $

PORTNAME=	matlab-installer
PORTVERSION=	0.2
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Mathworks(r) Matlab installation tool

RUN_DEPENDS=	${LINUXBASE}/usr/bin/gfortran:../../devel/linux-f10-devtools \
		${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/graphics/linux-f10-dri \
		${LOCALBASE}/sbin/mount_image:../../sysutils/diskimage-tools \
		webbrowser:../../www/webbrowser

USE_XZ=		yes
USE_LINUX=	yes
USE_LINUX_APPS=	ncurses-base
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	linux
JAVA_RUN=	yes

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} bin/matlab-browser man/man1/matlab-installer.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/matlab-browser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/matlab-installer.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
