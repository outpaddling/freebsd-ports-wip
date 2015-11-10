# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	bamtools
PORTVERSION=	2.4.0
CATEGORIES=	biology
MASTER_SITES=	http://github.com/pezmaster31/bamtools/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	API and toolkit for handling BAM files.

LICENSE=	MIT

# RUN_DEPENDS=	webbrowser:${PORTSDIR}/www/webbrowser

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#USES=		cmake 

.include <bsd.port.pre.mk>

# Just for speed: Recent GCC has better optimizer
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.if ${ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

do-build:
	(mkdir ${WRKSRC}/build && cd ${WRKSRC}/build && cmake .. && make)


.include <bsd.port.post.mk>
