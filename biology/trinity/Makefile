# New ports collection makefile for:	trinity
# Date created:		2013-05-22
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	trinity
PORTVERSION=	2014.04.13
CATEGORIES=	biology
MASTER_SITES=	https://sourceforge.net/projects/trinityrnaseq/files/
DISTNAME=	trinityrnaseq_r20140413p1

MAINTAINER=	jwbacon@tds.net
COMMENT=	RNA sequence assembly

USE_GMAKE=	yes
USE_GCC=	any

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp
MAKE_FLAGS+=	FORCE_UNSAFE_CONFIGURE=1

BUILD_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils
RUN_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${WRKSRC}/Makefile \
		${WRKSRC}/Chrysalis/Makefile* \
		${WRKSRC}/trinity-plugins/fastool/Makefile \
		${WRKSRC}/trinity-plugins/slclust/src/Makefile
	${REINPLACE_CMD} -e "s|configure CC=gcc47 CXX=g++47|configure CC=gcc47 CXX=g++47 LDFLAGS=-lexecinfo|g" ${WRKSRC}/Makefile
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++ \
		${WRKSRC}/Chrysalis/Makefile_${CXX}
	${MV} ${WRKSRC}/Chrysalis/Makefile_g++_x86_64 \
		${WRKSRC}/Chrysalis/Makefile_${CXX}_x86_64
	${REINPLACE_CMD} \
		-e 's|/bin/bash|/usr/bin/env bash|g' \
		-e 's|make |${GMAKE} |g' \
		-e 's|sort |gsort |g' \
		${WRKSRC}/trinity-plugins/coreutils/build_parallel_sort.sh \
		${WRKSRC}/trinity-plugins/collectl/build_collectl.sh

.include <bsd.port.mk>
