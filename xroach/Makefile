# $FreeBSD: head/games/xroach/Makefile 429499 2016-12-26 11:59:12Z rene $

PORTNAME=	xroach
PORTVERSION=	4.4
PORTREVISION=	3
CATEGORIES=	wip games
MASTER_SITES=   http://acadix.biz/Ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cockroaches hide under your windows

LICENSE=	PD

USES=		tar:xz
USE_XORG=	x11
PLIST_FILES=	bin/xroach man/man6/xroach.6.gz

do-install:
	${INSTALL_PROGRAM} -s ${WRKSRC}/xroach ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xroach.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
