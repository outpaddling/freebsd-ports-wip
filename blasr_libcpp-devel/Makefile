# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	blasr_libcpp
PORTVERSION=	2016.09.07
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Library for analyzing PacBio sequences

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash>0:shells/bash \
		pbbam>0:wip/pbbam
LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		compiler:c++11-lang gmake python

USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	c7d95cc8aec85ccb85161b67a613413c9ceee3cf

MAKEFILE=	makefile

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

post-patch:
	${REINPLACE_CMD} -e 's|SAIndex, UINT_MAX|SAIndex, INT_MAX|g' \
		${WRKSRC}/alignment/suffixarray/SuffixArray.hpp
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/makefile

do-configure:
	cd ${WRKSRC} && ./configure.py --no-pbbam \
		HDF5_INCLUDE=${LOCALBASE}/include HDF5_LIB=${LOCALBASE}/lib

# FIXME: pbbam is now available as a port, but enabling leads to compiler error
# with clang
post-configure:
	${REINPLACE_CMD} -e 's|define|undef|' ${WRKSRC}/pbdata/libconfig.h

# FIXME: Find out which headers actually need to be installed
do-install:
	for fn in `find ${WRKSRC} -name '*.h' -o -name '*.hpp'`; do \
		dir=`dirname $$fn | cut -d / -f 8-`; \
		${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
		${INSTALL_DATA} $$fn ${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
	done
	for fn in `find ${WRKSRC} -name '*.a'`; do \
		${INSTALL_DATA} $$fn ${STAGEDIR}${PREFIX}/lib; \
	done

.include <bsd.port.mk>
