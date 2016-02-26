# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bedtools2
PORTVERSION=	2.23.0
DISTVERSIONPREFIX=      v
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Swiss army knife for genome arithmetic

LICENSE=	GPLv2

# WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	arq5x

USES=	gmake

.include <bsd.port.pre.mk>

MAKE_JOBS_UNSAFE=	yes
# Just for speed: Recent GCC has better optimizer
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

#INSTALL_TARGET=	install-strip

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bedtools

.include <bsd.port.post.mk>
