# $FreeBSD$

PORTNAME=	libbacon
PORTVERSION=	1.2.2
CATEGORIES=	wip devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

CONFLICTS=	libbacon-1.[023456789]

PLIST_FILES=	lib/libbacon.a \
		include/bacon.h

USES=		tar:xz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
