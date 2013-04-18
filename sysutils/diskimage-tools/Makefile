# New ports collection makefile for:	diskimage-tools
# Date created:		2013-03-02
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	diskimage-tools
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for manipulating disk images

NO_BUILD=	yes

PLIST_FILES=	sbin/mount_image sbin/umount_image

do-install:
	${MKDIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/mount_image ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/umount_image ${PREFIX}/sbin

.include <bsd.port.mk>
