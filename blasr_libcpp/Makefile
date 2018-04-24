# $FreeBSD$

PORTNAME=	blasr_libcpp
#PORTVERSION=	2015.08.17
DISTVERSION=	g20180329
CATEGORIES=	wip biology
#MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library for analyzing PacBio sequences

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		gmake tar:xz
USE_GITUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	b038971c97eb5403b982c177eb44e488d25e9994

MAKEFILE=	makefile

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

# Uses C++11 syntax
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

post-patch:
	${REINPLACE_CMD} -e 's|SAIndex, UINT_MAX|SAIndex, INT_MAX|g' \
		${WRKSRC}/alignment/suffixarray/SuffixArray.hpp
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/makefile

do-configure:
	cd ${WRKSRC} && ./configure.py --no-pbbam \
		HDF5_INCLUDE=${LOCALBASE}/include HDF5_LIB=${LOCALBASE}/lib

post-configure:
	${REINPLACE_CMD} -e 's|define|undef|' ${WRKSRC}/libconfig.h

do-install:
	for fn in `find ${WRKSRC} -name '*.h' -o -name '*.hpp'`; do \
		dir=`dirname $$fn | cut -d / -f 8-`; \
		${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
		${INSTALL_DATA} $$fn ${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
	done
	for fn in `find ${WRKSRC} -name '*.a'`; do \
		${INSTALL_DATA} $$fn ${STAGEDIR}${PREFIX}/lib; \
	done

.include <bsd.port.post.mk>
