# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bedtools2
PORTVERSION=	2.25.0
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Swiss army knife for genome arithmetic

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	arq5x
GH_TAGNAME=	v${PORTVERSION}

USES=	gmake

.include <bsd.port.pre.mk>

MAKE_JOBS_UNSAFE=	yes
# Just for speed: Recent GCC has better optimizer
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

#INSTALL_TARGET=	install-strip
post-patch:
	@${REINPLACE_CMD} -e 's|CXX\t*=|CXX\t?|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bedtools

.include <bsd.port.post.mk>
