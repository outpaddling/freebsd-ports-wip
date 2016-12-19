# New ports collection makefile for:    cluster-admin
# Date created:         2010-1-15
# Whom:                 Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cluster-admin
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	auto-append-line:/usr/wip/sysutils/auto-admin

USES=		tar:xz

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include <bsd.port.mk>
