# $FreeBSD$

PORTNAME=	libpare
PORTVERSION=	1.1.1
CATEGORIES=	wip devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://outpaddling.mooo.com/~bacon/Acadix/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

USES=		tar:xz

PLIST_FILES=	lib/libpare.a \
		include/pare.h \
		man/man3/pare.3.gz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
