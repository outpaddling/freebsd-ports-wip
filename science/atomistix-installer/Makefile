# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: head/math/matlab-installer/Makefile 368845 2014-09-22 10:40:00Z xmj $

PORTNAME=	matlab-installer
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Easy installation of Linux Matlab(r) on FreeBSD

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	auto-ask:${PORTSDIR}/sysutils/auto-admin \
		/compat/linux/lib/libudev.so.0:/usr/wip/sysutils/linux-c6-libudev

USES=		tar:xz
USE_LINUX=	yes
USE_LINUX_APPS=	dri devtools

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/matlab-installer.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
