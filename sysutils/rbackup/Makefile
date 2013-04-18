# New ports collection makefile for:	fixperms
# Date created:		4 jan 2007
# Whom:			Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	rbackup
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	rsync backup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rbackup ${PREFIX}/bin

PLIST_FILES=	bin/rbackup

.include <bsd.port.mk>
