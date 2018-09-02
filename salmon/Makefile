# $FreeBSD$

PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		0.11.3
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification from RNA-seq using lightweight alignments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libomp.so:devel/openmp \
		libtbb.so:devel/tbb

USES=		cmake:noninja gmake shebangfix
# FIXME: Eliminiate fetchRapMap
SHEBANG_FILES=	scripts/*
USE_GITHUB=	yes
GH_ACCOUNT=	COMBINE-lab

#MAKE_JOBS_UNSAFE=	yes
LIBS+=		-L${LOCALBASE}/lib -lomp -lthr

post-configure:
	${REINPLACE_CMD} -e 's|&& make|\&\& gmake|g' \
		${WRKSRC}/CMakeFiles/libstadenio.dir/build.make \
		${WRKSRC}/CMakeFiles/libtbb.dir/build.make

.include <bsd.port.mk>
