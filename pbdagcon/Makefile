
PORTNAME=	pbdagcon
DISTVERSION=	g20180411
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Consensus algorithm implementation based on directed acyclic graphs

LICENSE=	BSD3CLAUSE

# argparse?
# Are these dazz_db and daligner versions OK?  Submodules are 2-year-old commits
BUILD_DEPENDS=	${COMMON_DEPENDS}
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libblasr.so:wip/blasr_libcpp \
		libhdf5-18.so:science/hdf5-18 \
		libhts.so:biology/htslib
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		gmake python shebangfix tar:xz
SHEBANG_FILES=	src/cpp/pbdagcon_wf.sh configure.py
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	c14c422e609a914f0139f7222202ac1bce7e3ef1

MAKEFILE=	makefile

# blasr_libcpp's Types.h is very common and could cause collisions.
# -I${LOCALBASE}/include/blasr_libcpp/pbdata should come before generic dirs
# Same for libconfig.h
CXXFLAGS+=	-I${LOCALBASE}/include/daligner \
		-I${LOCALBASE}/include/dazz_db \
		-I${LOCALBASE}/include/blasr_libcpp \
		-I${LOCALBASE}/include/blasr_libcpp/alignment \
		-I${LOCALBASE}/include/blasr_libcpp/pbdata \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/pbdagcon bin/dazcon bin/pbdagcon_wf.sh

COMMON_DEPENDS=	DAZZ_DB==1.0.14:wip/dazz_db \
		DALIGNER==1.0.52:wip/daligner \
		pbbam>=g20180416:biology/pbbam

post-patch:
	${REINPLACE_CMD} \
		-e 's|-lblasr|-lblasr -lpbbam -ldazz_db -ldaligner -lhts|g' \
		-e 's|-lhdf5_cpp -lhdf5| -lhdf5-18_cpp -lhdf5-18|g' \
		-e 's|$${DALIGNER_SRC}|$${LOCALBASE}/include|g' \
		-e 's|$${DAZZ_DB_SRC}|$${LOCALBASE}/include|g' \
		${WRKSRC}/configure.py
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/makefile
	${REINPLACE_CMD} \
		-e 's|CXXFLAGS =|CXXFLAGS +=|g' \
		-e 's|CFLAGS =|CFLAGS +=|g' \
		-e 's|c++11|c++0x|g' \
		-e 's|DB.o QV.o align.o ||g' \
		-e 's|^vpath|# vpath|g' \
		${WRKSRC}/src/cpp/makefile

do-configure:
	cd ${WRKSRC} && ./configure.py

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/cpp/pbdagcon \
		${WRKSRC}/src/cpp/dazcon \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/src/cpp/pbdagcon_wf.sh \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
