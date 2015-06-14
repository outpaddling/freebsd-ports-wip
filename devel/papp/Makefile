# New ports collection makefile for:	app
# Date created:		18 September 2009
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD: ports/devel/papp/Makefile,v 1.2 2012/11/17 05:56:37 svnexp Exp $
#

PORTNAME=	papp
PORTVERSION=	0.3.2
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Assembly Preprocessor

USES=		tar:xz

LICENSE=	BSD3CLAUSE

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX} \
		STAGEDIR=${STAGEDIR}

.include <bsd.port.mk>
