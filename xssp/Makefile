# $FreeBSD$

PORTNAME=	xssp
PORTVERSION=	3.0.1
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Software for creating DSSP and HSSP files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# Need: libzeep
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		autoreconf
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	cmbi

# CXXFLAGS+=	-std=gnu++11
USE_GCC=	any

post-patch:
	@${REINPLACE_CMD} -e 's|tr1/tuple.hpp|tuple/tuple.hpp|g' \
		${WRKSRC}/src/mas.cpp \
		${WRKSRC}/src/primitives-3d.h
	@${REINPLACE_CMD} -e 's|std::tr1|std|g' \
		${WRKSRC}/src/primitives-3d.cpp \
		${WRKSRC}/src/structure.h \
		${WRKSRC}/src/primitives-3d.h \
		${WRKSRC}/src/structure.cpp \
		${WRKSRC}/src/dssp.cpp

.include <bsd.port.mk>
