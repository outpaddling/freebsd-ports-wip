# $FreeBSD: head/devel/libgamepad/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	libgamepad
PORTVERSION=	0.1.2
CATEGORIES=	wip devel games
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generic gamepad API

LICENSE=	BSD2CLAUSE

USES=		tar:xz

pre-build:
	(cd ${WRKSRC} && make depend)

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
