# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bamtools
PORTVERSION=	2.4.0
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	API and toolkit for handling BAM files

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake:outsource
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pezmaster31
GH_TAGNAME=	v${PORTVERSION}

.include <bsd.port.pre.mk>

# Just for speed: Recent GCC has better optimizer
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

.include <bsd.port.post.mk>
