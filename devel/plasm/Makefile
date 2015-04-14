# New ports collection makefile for:    plasm
# Date created:         2010-07-21
# Whom:                 Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=       plasm
PORTVERSION=    0.1
CATEGORIES=     devel
MASTER_SITES=   http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=     jwbacon@tds.net
COMMENT=        Portable Assembler

PLIST_FILES=    bin/asepc bin/asepc.bin include/epc.h

MAN1=           asepc.1

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	papp:../../devel/papp

USES=		tar:xz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

pre-build:
	make depend

.include <bsd.port.mk>
