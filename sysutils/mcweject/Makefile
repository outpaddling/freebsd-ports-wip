# Created by: Jason Bacon <jbacon@mcw.edu>
# $FreeBSD: head/sysutils/mcweject/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	mcweject
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Removable media eject

SUB_FILES=	pkg-message

CONFLICTS=	eject-[0-9]*
PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		tar:xz

# PLIST_FILES=	sbin/eject share/examples/mcweject/eject.allow
PLIST_DIRS=	share/examples/mcweject

MAKE_ARGS+=	STAGEDIR=${STAGEDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
