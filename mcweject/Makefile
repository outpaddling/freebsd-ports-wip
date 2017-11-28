# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD: head/sysutils/mcweject/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	mcweject
PORTVERSION=	1.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Removable media eject

LICENSE=	BSD3CLAUSE

SUB_FILES=	pkg-message

CONFLICTS=	eject-[0-9]*

USES=		tar:xz

MAKE_ARGS+=	STAGEDIR=${STAGEDIR}

.include <bsd.port.mk>
