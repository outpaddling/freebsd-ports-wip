# New ports collection makefile for:	ezquota
# Date created:		2012-02-14
# Whom:			Jason Bacon <jwb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ezquota
PORTVERSION=	0.1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quota script for UFS+ZFS

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ezquota ${PREFIX}/bin

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
