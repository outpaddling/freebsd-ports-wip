# New ports collection makefile for:	wifi_select
# Date created:		2010-04-02
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	wifi_select
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Select from available wireless networks

NO_BUILD=	yes

USE_RC_SUBR=	wifi_select

MAN1=		wifi_select.1

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}_daemon ${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/stations.conf.sample ${DATADIR}
	${INSTALL_DATA} -m 0600 ${WRKSRC}/stations.conf.sample ${PREFIX}/etc/${PORTNAME}/stations.conf
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.mdoc ${MAN1PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
