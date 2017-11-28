# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bedtools2
PORTVERSION=	2.26.0
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Swiss army knife for genome arithmetic

LICENSE=	GPLv2

USES+=		gmake python:build shebangfix
SHEBANG_FILES=	scripts/*

USE_GITHUB=	yes
GH_ACCOUNT=	arq5x

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bedtools

.include <bsd.port.mk>
