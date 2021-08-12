PORTNAME=	vbz-compression
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	wip
MASTER_SITES=	

MAINTAINER=	bacon@barracuda.uits.uwm.edu
COMMENT=	Variable byte integer encoding to compress nanopore signal data

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libzstd.so:archivers/zstd

USES=		cmake
USE_GITHUB=	yes

GH_ACCOUNT=	nanoporetech
GH_PROJECT=	vbz_compression

CMAKE_ARGS=	-DENABLE_CONAN=OFF -DENABLE_PERF_TESTING=OFF -DENABLE_PYTHON=OFF

.include <bsd.port.mk>
