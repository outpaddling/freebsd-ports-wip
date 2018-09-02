# $FreeBSD$

PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		0.11.3
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libomp.so:devel/openmp \
		libtbb.so:devel/tbb \
		libboost_system.so:devel/boost-libs

USES=		cmake:noninja gmake shebangfix
SHEBANG_FILES=	scripts/*
USE_GITHUB=	yes
GH_ACCOUNT=	COMBINE-lab

LIBS+=		-L${LOCALBASE}/lib -lomp -lthr
PLIST_FILES=	bin/salmon lib/libsalmon_core.a

# FIXME: Eliminiate fetchRapMap

post-patch:
	@${REINPLACE_CMD} -e 's|tbbmalloc_proxy||g' ${WRKSRC}/CMakeLists.txt

post-configure:
	@${REINPLACE_CMD} -e 's|&& make|\&\& gmake|g' \
		${WRKSRC}/CMakeFiles/libstadenio.dir/build.make

.include <bsd.port.mk>
