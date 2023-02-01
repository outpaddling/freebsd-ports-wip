PORTNAME=	ncbi-vdb
DISTVERSION=	3.0.2
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's virtualized back-end for accessing Sequence Read Archive
WWW=		https://github.com/ncbi/ncbi-vdb/wiki

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	libs/search/nucstrstr.c requires SSE2 instructions

BUILD_DEPENDS=	bash:shells/bash \
		libepoll-shim>0:devel/libepoll-shim
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5

USES=		cmake:noninja compiler:c11 perl5 shebangfix
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

SHEBANG_GLOB=	*.sh *.pl

# Temporary for patching
# MAKE_JOBS_UNSAFE=	yes

post-extract:
	${MKDIR} ${WRKSRC}/interfaces/os/freebsd
	${CP} ${WRKSRC}/interfaces/os/linux/os-native.h \
		${WRKSRC}/interfaces/os/freebsd
	${MKDIR} ${WRKSRC}/libs/kfs/freebsd
	${CP} ${WRKSRC}/libs/kfs/unix/sysfile-priv.h \
		${WRKSRC}/libs/kfs/freebsd
	${CP} ${FILESDIR}/endian.h ${WRKSRC}/interfaces/os/freebsd
	${CP} ${FILESDIR}/byteswap.h ${WRKSRC}/interfaces/os/freebsd

.include <bsd.port.mk>
