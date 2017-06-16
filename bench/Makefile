# New ports collection makefile for:	bench
# Date created:		2011-08-28
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bench
PORTVERSION=	0.2
CATEGORIES=	wip benchmarks
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	General benchmark for CPU, RAM, and disk

LICENSE=	BSD2CLAUSE

USES=		tar:xz
#USE_GCC=	yes

OPTIONS_DEFINE=	GCC CLANG
GCC_DESC=	Use newer GCC
CLANG_DESC=	Use newer Clang

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCC}
USE_GCC=	yes
.endif

.if ${PORT_OPTIONS:MCLANG}
BUILD_DEPENDS+=	clang37:lang/clang37
CC=		clang37
.endif

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} MANPREFIX=${STAGEDIR}${MANPREFIX}

.include <bsd.port.mk>
