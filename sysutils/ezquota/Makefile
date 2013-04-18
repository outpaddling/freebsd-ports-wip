# New ports collection makefile for:	ezquota
# Date created:		2012-02-14
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	ezquota
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	Quota script for UFS+ZFS

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ezquota ${PREFIX}/bin

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
