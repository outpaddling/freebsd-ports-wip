# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	tabixpp
PORTVERSION=	c39bac6930dac16decdfc682489efc7d608e8b94
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ wrapper to tabix indexer

LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib

USES=		tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

PLIST_FILES=	bin/tabix++ include/tabix.hpp

CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	HTS_HEADERS='' LIBPATH=-L${LOCALBASE}/lib HTS_LIB=''

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
