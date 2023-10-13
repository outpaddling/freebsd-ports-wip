PORTNAME=	gcta
DISTVERSIONPREFIX=	v
DISTVERSION=	1.94.1
CATEGORIES=	wip biology
MASTER_SITES=	https://gitlab.com/libeigen/eigen/-/archive/${EIGEN_VERSION}/:eigen

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Complex Trait Analysis
WWW=		https://cnsgenomics.com/software/gcta/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	spectra>0:math/spectra
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgsl.so:math/gsl \
		libopenblas.so:math/openblas \
		libsqlite3.so:databases/sqlite3 \
		libzstd.so:archivers/zstd

USES=		cmake eigen:3
USE_GITHUB=	yes

GH_ACCOUNT=	jianyangqt
GH_TUPLE=	zhilizheng:plink-ng:3744540:plink/submods/plink-ng

CONFIGURE_ENV+=	EIGEN3_INCLUDE_DIR=${LOCALBASE}/include/eigen3 \
		BOOST_LIB=${LOCALBASE}/include \
		OPENBLAS=${LOCALBASE}/include \
		SPECTRA_INCLUDE_DIR=${LOCALBASE}/include/Spectra \
		SPECTRA_LIB=${LOCALBASE}/lib

# Temporary for clean build output
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/gcta

.include <bsd.port.mk>
