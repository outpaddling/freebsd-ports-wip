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

PLIST_FILES=    bin/asepc \
		bin/asepc.bin \
		include/epc.h \
		man/man1/asepc.1.gz

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	papp:/usr/wip/devel/papp

USES=		tar:xz
.include <bsd.port.pre.mk>
.if ${ARCH} == "powerpc"
USE_GCC=	yes
.endif

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

pre-build:
	make depend

.include <bsd.port.post.mk>
