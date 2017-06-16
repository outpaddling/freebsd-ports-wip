# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bedtools2
PORTVERSION=	2.23.0
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Swiss army knife for genome arithmetic

LICENSE=	GPLv2

USES+=		gmake python:build

USE_GITHUB=	yes
GH_ACCOUNT=	arq5x

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bedtools

.include <bsd.port.mk>
