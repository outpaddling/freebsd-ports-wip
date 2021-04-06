
PORTNAME=	bedops
PORTVERSION=	2.4.20
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
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

CXXFLAGS+=	-I${LOCALBASE}/include

# Unsure
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${CP} ${FILESDIR}/Makefile.simple ${WRKSRC}/system.mk

.include <bsd.port.mk>
