
PORTNAME=	xssp
PORTVERSION=	3.0.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Software for creating DSSP and HSSP files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libzeep.so:wip/libzeep

USES=		autoreconf
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	cmbi

# unknown-pragmas for boost header on 10.4
CXXFLAGS+=	-Wno-unused-const-variable -Wno-unknown-pragmas -I${LOCALBASE}/include
LDFLAGS+=	-L${PREFIX}/lib

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
	@${REINPLACE_CMD} -e 's|tr1/cmath.hpp|units/cmath.hpp|g' \
		${WRKSRC}/src/hssp-nt.cpp

.include <bsd.port.mk>
