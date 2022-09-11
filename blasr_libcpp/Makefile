PORTNAME=	blasr_libcpp
DISTVERSION=	g20180329
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library for analyzing PacBio sequences
WWW=		https://github.com/PacificBiosciences/blasr_libcpp

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pbbam>=g20180416:biology/pbbam \
		bash:shells/bash
LIB_DEPENDS=	libhdf5-18.so:science/hdf5-18

USES=		gmake python shebangfix tar:xz
SHEBANG_FILES=	configure.py \
		tools/check-formatting tools/format-all \
		bamboo_build.sh travis.sh DEVELOPER.md \
		scripts/ci/checkout-submodules.sh scripts/ci/build.sh
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	b038971c97eb5403b982c177eb44e488d25e9994

MAKEFILE=	makefile
CXXFLAGS+=	-I${LOCALBASE}/include/hdf5-18 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|SAIndex, UINT_MAX|SAIndex, INT_MAX|g' \
		${WRKSRC}/alignment/suffixarray/SuffixArray.hpp
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|-lhdf5|-lhdf5-18|g' \
		${WRKSRC}/hdf/makefile ${WRKSRC}/unittest/makefile
	@${REINPLACE_CMD} -e 's|-std=c++14|-std=c++1y|g' \
		${WRKSRC}/alignment/makefile \
		${WRKSRC}/pbdata/makefile \
		${WRKSRC}/meson.build \
		${WRKSRC}/hdf/makefile \
		${WRKSRC}/unittest/makefile

do-configure:
	(cd ${WRKSRC} && ./configure.py --no-pbbam \
		HDF5_INCLUDE=${LOCALBASE}/include \
		HDF5_LIB=${LOCALBASE}/lib \
		PBBAM_INCLUDE=${LOCALBASE}/include)

do-install:
	for fn in `find ${WRKSRC} -name '*.h' -o -name '*.hpp'`; do \
		relpath=$${fn#${WRKSRC}/}; \
		dir=`dirname $$relpath`; \
		@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
		${INSTALL_DATA} $$fn \
			${STAGEDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
	done
	for lib in pbdata/libpbdata hdf/libpbihdf alignment/libblasr; do \
		${INSTALL_DATA} ${WRKSRC}/$$lib.a ${STAGEDIR}${PREFIX}/lib; \
		${INSTALL_DATA} ${WRKSRC}/$$lib.so ${STAGEDIR}${PREFIX}/lib; \
	done
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
