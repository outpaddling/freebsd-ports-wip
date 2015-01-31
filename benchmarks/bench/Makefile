# New ports collection makefile for:	bench
# Date created:		2011-08-28
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	bench
PORTVERSION=	0.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	General benchmark for CPU, RAM, and disk

USES=		tar:xz

PLIST_FILES=	bin/bench

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} MANPREFIX=${STAGEDIR}${MANPREFIX}

.include <bsd.port.mk>
