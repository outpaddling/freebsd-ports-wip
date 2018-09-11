# $FreeBSD$

PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		0.11.3
# Does not seem to fit GH_ structure.  salmon-v0.11.3.zip is an alternative
# RapMap distfile.
CATEGORIES=		wip biology
MASTER_SITES+=		https://github.com/COMBINE-lab/RapMap/archive/ \
			https://github.com/COMBINE-lab/libgff/archive/ \
			https://github.com/COMBINE-lab/staden-io_lib/archive/
DISTFILES+=		salmon-v0.11.3.zip v1.1.tar.gz v1.14.8.1.tar.gz
DIST_SUBDIR=		salmon
EXTRACT_ONLY=		COMBINE-lab-salmon-v${DISTVERSION}_GH0.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		autoconf:devel/autoconf \
		cereal>=1.2.2:wip/cereal
LIB_DEPENDS=	libtbb.so:devel/tbb \
		libboost_system.so:devel/boost-libs

USES=		cmake:noninja compiler:gcc-c++11-lib gmake shebangfix
SHEBANG_FILES=	scripts/*
USE_GITHUB=	yes
GH_ACCOUNT=	COMBINE-lab

LIBS+=		-L${LOCALBASE}/lib -lthr
PLIST_FILES=	bin/salmon lib/libsalmon_core.a
CONFIGURE_ENV=	DISTDIR=${DISTDIR} DIST_SUBDIR=${DIST_SUBDIR}
CMAKE_ARGS+=	-DDISTDIR:PATH=${DISTDIR} -DDIST_SUBDIR:PATH=${DIST_SUBDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|tbbmalloc_proxy||g' ${WRKSRC}/CMakeLists.txt

post-configure:
	@${REINPLACE_CMD} -e 's|&& make|\&\& gmake|g' \
		${WRKSRC}/CMakeFiles/libstadenio.dir/build.make

.include <bsd.port.mk>
