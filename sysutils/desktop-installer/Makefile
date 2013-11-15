# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: sysutils/desktop-installer/Makefile 316098 2013-04-19 11:46:48Z madpilot $

PORTNAME=	desktop-installer
PORTVERSION=	0.4.7
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Quickly configure a FreeBSD desktop system

LICENSE=	BSD

RUN_DEPENDS=	auto-admin>=0.3.3:../../sysutils/auto-admin

USE_XZ=		yes

NO_BUILD=	yes

MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Doc/${PORTNAME}.man \
		${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -r ${WRKSRC}/Data/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/Scripts
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${DATADIR}/Scripts

.include <bsd.port.pre.mk>
post-patch:
	${REINPLACE_CMD} 's|/etc/mtree|$${PORTSDIR=/usr/ports}/Templates|' \
		${WRKSRC}/${PORTNAME}
	${REINPLACE_CMD} \
		's|DATADIR=Data|DATADIR=${STAGEDIR}${PREFIX}/share/desktop-installer|g' \
		${WRKSRC}/desktop-installer

.include <bsd.port.post.mk>
