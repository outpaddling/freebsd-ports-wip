# Created by: Dan Siercks
# $FreeBSD$

PORTNAME=	scythe
PORTVERSION=	2016.02.10
CATEGORIES=	biology

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	3'-end adapter contaminant trimmer

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	vsbuffalo
GH_TAGNAME=	20d3cff7d7f483bd779aff75f861e93708c0a2b5

USES=		gmake

.include <bsd.port.pre.mk>

# Hack for X120e
CFLAGS+=	-I/usr/include/clang/3.3

# Hack for emmintrin.h error?
.if ${ARCH} == i386
CFLAGS+=	-msse2
.endif

PLIST_FILES=	bin/scythe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scythe \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
