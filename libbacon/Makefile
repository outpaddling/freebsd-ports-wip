# $FreeBSD$

PORTNAME=	libbacon
DISTVERSION=	1.2.2-1
DISTVERSIONSUFFIX=	-g2e181aa
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

PLIST_FILES=	lib/libbacon.a include/bacon.h

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
