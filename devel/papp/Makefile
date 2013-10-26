# New ports collection makefile for:	app
# Date created:		18 September 2009
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD: ports/devel/papp/Makefile,v 1.2 2012/11/17 05:56:37 svnexp Exp $
#

PORTNAME=	papp
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Assembly Preprocessor

LICENSE=	BSD

MAN1=		papp.1

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
