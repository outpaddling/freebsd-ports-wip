# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	1.0.0p20171116
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ wrapper to tabix indexer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhts.so:biology/htslib

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	6bbe6907d0d4b63e9c00e130a9a66d509bdcd29d

CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	HTS_HEADERS='' LIBPATH=-L${LOCALBASE}/lib HTS_LIB=''

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/tabix++ \
		include/tabix.hpp \
		lib/libtabix.a \
		lib/libtabix.so \
		lib/libtabix.so.1

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${CP} ${STAGEDIR}${PREFIX}/lib/libtabix.so.1 \
		${STAGEDIR}${PREFIX}/lib/libtabix.so

.include <bsd.port.mk>
