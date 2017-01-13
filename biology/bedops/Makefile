# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	bedops
PORTVERSION=	2.4.20
DISTVERSIONPREFIX=v
CATEGORIES=	biology

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	High-performance genomic feature operations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

# Depends
# LIBS = jansson/lib/libjansson.a bzip2/libbz2.a zlib/libz.a
# bzip2 and zlib are in FreeBSD base
LIB_DEPENDS+=	libjansson.so:devel/jansson

USES=		gmake

USE_GITHUB=	yes

ALL_TARGET=	default

# Unsure
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${CP} ${FILESDIR}/Makefile.simple ${WRKSRC}/system.mk

.include <bsd.port.mk>
