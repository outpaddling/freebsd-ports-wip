# $FreeBSD$

PORTNAME=	pbdagcon
PORTVERSION=	2015.08.19
CATEGORIES=	wip biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Consensus algorithm implementation based on directed acyclic graphs

LICENSE=	BSD3CLAUSE

# argparse?
BUILD_DEPENDS=	${LOCALBASE}/lib/libblasr.a:wip/blasr_libcpp \
		dazz_db>=2015.08.17:wip/dazz_db \
		daligner>=2015.08.17:wip/daligner
LIB_DEPENDS+=	libboost_filesystem.so:devel/boost-libs
# FIXME: What versions of dazz_db and daligner do we really depend on?
RUN_DEPENDS+=	dazz_db>=2015.08.17:wip/dazz_db \
		daligner>=2015.08.17:wip/daligner
#RUN_DEPENDS+=	dazz_db>=${PORTVERSION}:wip/dazz_db \
#		daligner>=${PORTVERSION}:wip/daligner

USES=		gmake shebangfix tar:xz
SHEBANG_FILES=	src/cpp/pbdagcon_wf.sh

MAKEFILE=	makefile

# FIXME: blasr_libcpp's Types.h is very common and could cause collisions
# Same for libconfig.h
CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/blasr_libcpp \
		-I${LOCALBASE}/include/blasr_libcpp/alignment \
		-I${LOCALBASE}/include/blasr_libcpp/pbdata
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/pbdagcon bin/dazcon bin/pbdagcon_wf.sh

post-patch:
	${REINPLACE_CMD} \
		-e 's|-lblasr|-lblasr -lhdf5_cpp -lhdf5 -ldaligner -ldazzdb|g' \
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
	cd ${WRKSRC} && ./configure.py --no-pbbam

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/cpp/pbdagcon \
		${WRKSRC}/src/cpp/dazcon \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/src/cpp/pbdagcon_wf.sh \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
