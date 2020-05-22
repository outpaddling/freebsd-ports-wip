# $FreeBSD$

PORTNAME=	twintk
DISTVERSION=	0.9.4-1
DISTVERSIONSUFFIX=	-g440383c
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libbacon>0:wip/libbacon

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

INSTALL_TARGET=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX} \
		install

.include <bsd.port.mk>
