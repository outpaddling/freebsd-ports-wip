PORTNAME=	bedops
PORTVERSION=	2.4.41
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance genomic feature operations
WWW=		https://github.com/bedops/bedops

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

# FIXME: Find a way to support ENODATA
pre-configure:
	${REINPLACE_CMD} \
		-e '/^LOCAL/d' \
		-e 's|-I$${LOCALJANSSONINCDIR} -I$${LOCALBZIP2INCDIR} -I$${LOCALZLIBINCDIR}|-I${LOCALBASE}/include|g' \
		-e 's|-L$${LOCALJANSSONLIBDIR} -L$${LOCALBZIP2LIBDIR} -L$${LOCALZLIBDIR}|-L${LOCALBASE}/lib|g' \
		-e 's|$${LOCALJANSSONLIB} $${LOCALBZIP2LIB} $${LOCALZLIBLIB}|-ljansson -lbz2 -lz|g' \
		${WRKSRC}/applications/bed/*/src/Makefile
	${REINPLACE_CMD} -e 's|deflateInit2cpp|deflateInit2|g' \
		${WRKSRC}/applications/bed/starch/src/starchcat.c \
		${WRKSRC}/interfaces/src/data/starch/starchFileHelpers.c
	${REINPLACE_CMD} -e 's|ENODATA|EIO|g' \
		${WRKSRC}/applications/bed/conversion/src/convert2bed.c

.include <bsd.port.mk>
