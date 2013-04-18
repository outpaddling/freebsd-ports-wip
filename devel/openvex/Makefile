# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: ports/devel/openvex/Makefile,v 1.1 2012/09/25 12:04:48 makc Exp $

PORTNAME=	openvex
PORTVERSION=	0.5.2
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open source firmware for Vex robotics controllers

LICENSE=	GPLv3

BUILD_DEPENDS=	sdcc:${PORTSDIR}/lang/sdcc \
		gpasm:${PORTSDIR}/devel/gputils
RUN_DEPENDS=	vexctl:${PORTSDIR}/devel/roboctl \
		sdcc:${PORTSDIR}/lang/sdcc \
		gpasm:${PORTSDIR}/devel/gputils

MAN1=		openvex.1 openvex-new-project.1

ALL_TARGET=	all clean

.include <bsd.port.mk>
