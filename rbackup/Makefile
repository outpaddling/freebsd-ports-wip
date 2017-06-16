# New ports collection makefile for:	fixperms
# Date created:		4 jan 2007
# Whom:			Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	rbackup
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	rsync backup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rbackup ${PREFIX}/bin

PLIST_FILES=	bin/rbackup

.include <bsd.port.mk>
