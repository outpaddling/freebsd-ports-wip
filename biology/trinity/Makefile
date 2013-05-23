# New ports collection makefile for:	trinity
# Date created:		2013-05-22
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	trinity
PORTVERSION=	2013.02.25
CATEGORIES=	biology
MASTER_SITES=	https://sourceforge.net/projects/trinityrnaseq/files/
DISTNAME=	trinityrnaseq_r2013-02-25
EXTRACT_SUFX=	.tgz

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=

USE_GMAKE=	yes

FETCH_ARGS+=	-F

CFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp
MAKE_FLAGS+=	FORCE_UNSAFE_CONFIGURE=1

BUILD_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils
RUN_DEPENDS+=	gsort:${PORTSDIR}/sysutils/coreutils

post-patch:
	${REINPLACE_CMD} \
		-e 's|logl|log|g' \
		-e 's|expl|exp|g' \
		${WRKSRC}/trinity-plugins/rsem-1.2.3/sam/errmod.c
	${REINPLACE_CMD} \
		-e 's|/bin/bash|/usr/bin/env bash|g' \
		-e 's|make |${GMAKE} |g' \
		-e 's|sort |gsort |g' \
		${WRKSRC}/trinity-plugins/coreutils/build_parallel_sort.sh \
		${WRKSRC}/trinity-plugins/collectl/build_collectl.sh

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
