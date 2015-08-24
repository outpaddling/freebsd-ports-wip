# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD: head/devel/linux-c6-ncurses-base/Makefile 392922 2015-07-26 13:35:29Z antoine $

PORTNAME=	${LINUX_NAME}-base
PORTVERSION=	5.7
PORTREVISION=	2
CATEGORIES=	devel linux

MAINTAINER=	jwbacon@tds.net
COMMENT=	Terminfo database required by Linux ncurses programs

USE_LINUX=	c6
USE_LINUX_RPM=	yes
LINUX_NAME=	ncurses

RPMVERSION=	4.20090207.el6
SRC_DISTFILES=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}
DESCR=	${.CURDIR}/../${LINUX_NAME}/pkg-descr

.include <bsd.port.mk>
