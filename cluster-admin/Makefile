# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	cluster-admin
PORTVERSION=	0.3
CATEGORIES=	wip sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	auto-append-line:wip/auto-admin

USES=		tar:xz

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include <bsd.port.mk>
