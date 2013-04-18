# New ports collection Makefile for:	mcweject
# Date created:				11 Jan 2005
# Whom:					Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	ddclone
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Removable media eject

MAN1=		ddclone.1
MANCOMPRESSED=	yes

NO_BUILD=	yes

PLIST_FILES=	sbin/ddclone

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ddclone ${PREFIX}/sbin/ddclone
	${INSTALL_MAN} ${WRKSRC}/ddclone.1 ${PREFIX}/man/man1
	${GZIP_CMD} -best ${PREFIX}/man/man1/ddclone.1

.include <bsd.port.mk>
