# Created by: Jason Wayne Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	mothur
PORTVERSION=	1.36.1
DISTVERSIONPREFIX=      v
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Bioinformatics tool for the microbial ecology community

LICENSE=	GPLv3

USES=		gmake shebangfix
SHEBANG_FILES=	source/uchime_src/mk
# FIXME: Does not build with clang: Canberra type not found
USE_GCC=	yes

LIB_DEPENDS=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes

MAKEFILE=	makefile
ALL_TARGET=	mothur
PLIST_FILES=	mothur

post-patch:
	${REINPLACE_CMD} -e 's|-O3|-I${LOCALBASE}/include|g' \
			-e 's|-arch x86_64||g' \
			-e 's|$${BOOST_LIBRARY_DIR}/libboost_iostreams.a|-lboost_iostreams|g' \
			-e 's|$${BOOST_LIBRARY_DIR}/zlib.a|-lz|g' \
			${WRKSRC}/makefile
	${REINPLACE_CMD} -e 's|g++|${CXX}|g' ${WRKSRC}/source/uchime_src/mk

.include <bsd.port.mk>
