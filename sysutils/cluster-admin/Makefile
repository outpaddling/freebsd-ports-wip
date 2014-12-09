# New ports collection makefile for:    cluster-admin
# Date created:         2010-1-15
# Whom:                 Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	cluster-admin
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for building and managing HPC clusters

RUN_DEPENDS=	auto-append-line:/usr/wip/sysutils/auto-admin

USES=		tar:xz
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/Common/Sys-scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} \
		${WRKSRC}/FreeBSD/Sys-scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} \
		${WRKSRC}/Common/User-scripts/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/FreeBSD/User-scripts/* ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/FreeBSD/Man && for f in *.mdoc; \
	do \
		${INSTALL_MAN} $${f} \
			${STAGEDIR}${PREFIX}/man/man1/$${f%.mdoc}.1; \
	done)
	${MKDIR} ${STAGEDIR}${DATADIR}/WWW
	${INSTALL_DATA} ${WRKSRC}/FreeBSD/Share/* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/FreeBSD/WWW/* ${STAGEDIR}${DATADIR}/WWW

.include <bsd.port.mk>
