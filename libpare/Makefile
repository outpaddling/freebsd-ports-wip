
PORTNAME=	libpare
DISTVERSION=	1.1.1
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

PLIST_FILES=	lib/libpare.a \
		include/pare.h \
		man/man3/pare.3.gz

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
