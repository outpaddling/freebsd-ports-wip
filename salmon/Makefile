PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		1.5.2
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# Check cereal version
BUILD_DEPENDS=	bash:shells/bash \
		autoconf:devel/autoconf \
		cereal>=1.3.0:devel/cereal
LIB_DEPENDS=	libtbb.so:devel/onetbb \
		libboost_system.so:devel/boost-libs

# USES=		cmake:noninja compiler:gcc-c++11-lib gmake shebangfix
USES=		cmake shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	COMBINE-lab
SHEBANG_FILES=	scripts/*

#LIBS+=		-L${LOCALBASE}/lib -lthr
PLIST_FILES=	bin/salmon lib/libsalmon_core.a
#CONFIGURE_ENV=	DISTDIR=${DISTDIR} DIST_SUBDIR=${DIST_SUBDIR}
#CMAKE_ARGS+=	-DDISTDIR:PATH=${DISTDIR} -DDIST_SUBDIR:PATH=${DIST_SUBDIR}
# FreeBSD's base malloc is jemalloc
CMAKE_ARGS+=	-DHAVE_FAST_MALLOC:BOOL=on

.include <bsd.port.mk>
