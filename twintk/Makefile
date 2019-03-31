# $FreeBSD$

PORTNAME=	twintk
PORTVERSION=	0.9.4
CATEGORIES=	wip devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://outpaddling.mooo.com/~bacon/Acadix/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Misc functions

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libbacon.a:wip/libbacon

USES=		tar:xz

# Makefile uses PREFIX to determine location of terminfo db, so it should be
# the final destination, not the staged.
INSTALL_TARGET=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX} \
		install

.include <bsd.port.mk>
