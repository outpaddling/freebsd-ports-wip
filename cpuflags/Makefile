# Created by: Quentin Stievenart <acieroid@awesom.eu>
# $FreeBSD: head/devel/cpuflags/Makefile 453238 2017-10-31 14:51:53Z olgeni $

PORTNAME=	cpuflags
PORTVERSION=	1.41
CATEGORIES=	wip devel sysutils
MASTER_SITES=	http://awesom.eu/~acieroid/files/ports/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Determine compiler flags to best target current cpu

RUN_DEPENDS=	gcc:lang/gcc

post-install:
	${REINPLACE_CMD} -i '' -e "s,@@SH@@,${SH:Q}," ${STAGEDIR}${PREFIX}/bin/cpuflags

.include <bsd.port.mk>
