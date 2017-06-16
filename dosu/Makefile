# New ports collection makefile for:	dosu
# Date created:		3 Jan 2006
# Whom:			Jason W. Bacon
#
# $FreeBSD$
#

PORTNAME=	dosu
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Run commands as another user

MAN1=		dosu.1

post-extract:
	${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|g' ${WRKSRC}/dosu.1

.include <bsd.port.mk>
