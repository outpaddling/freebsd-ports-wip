# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/sysutils/desktop-installer/Makefile 414558 2016-05-03 21:02:33Z arved $

PORTNAME=	desktop-installer
PORTVERSION=	0.5.4
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Quickly configure a FreeBSD desktop system

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	auto-admin>=0.4.0:/usr/wip/sysutils/auto-admin

USES=		tar:xz

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Doc/${PORTNAME}.man \
		${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/Data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/Scripts
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${DATADIR}/Scripts

.include <bsd.port.mk>
