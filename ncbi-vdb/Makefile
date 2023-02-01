PORTNAME=	ncbi-vdb
DISTVERSION=	3.0.2
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's virtualized back-end for accessing Sequence Read Archive
WWW=		https://github.com/ncbi/ncbi-vdb/wiki

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

# Can we use SIMDE?
ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	libs/search/nucstrstr.c requires SSE2 instructions

BUILD_DEPENDS=	bash:shells/bash \
		libepoll-shim>0:devel/libepoll-shim
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5

USES=		cmake shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

SHEBANG_GLOB=	*.sh *.pl

post-extract:
	@${MKDIR} ${WRKSRC}/interfaces/os/freebsd
	@${CP} ${FILESDIR}/*.h ${WRKSRC}/interfaces/os/freebsd

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib64/libncbi-vdb.so.3.0.2
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib64/libncbi-wvdb.so.3.0.2

.include <bsd.port.mk>
