# New ports collection makefile for:	openvex
# Date created:		2010-01-23
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	openvex4
PORTVERSION=	0.4.4
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/
DISTNAME=	OpenVex-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open firmware for Vex PIC-based robotics controller

BUILD_DEPENDS=	sdcc:${PORTSDIR}/lang/sdcc \
		gpasm:${PORTSDIR}/devel/gputils
RUN_DEPENDS=	vexctl:${PORTSDIR}/devel/roboctl \
		sdcc:${PORTSDIR}/lang/sdcc \
                gpasm:${PORTSDIR}/devel/gputils

CONFLICTS=	openvex-0.5.*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/robotize_freebsd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/openvex_new_project ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/* ${DATADIR}

.include <bsd.port.mk>
