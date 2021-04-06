
PORTNAME=	vt
DISTVERSION=	0.57721
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Discovers short variants from Next Generation Sequencing data

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/tclap.pc:devel/tclap
LIB_DEPENDS=	libhts.so:biology/htslib \
		libsvm.so:science/libsvm \
		libdeflate.so:archivers/libdeflate \
		libcurl.so:ftp/curl

USES=		compiler:c++0x gmake ssl
USE_GITHUB=	yes

GH_ACCOUNT=	atks

PLIST_FILES=	bin/vt

post-extract:
	${RM} -rf \
		${WRKSRC}/lib/htslib \
		${WRKSRC}/lib/libdeflate \
		${WRKSRC}/lib/libsvm \
		${WRKSRC}/lib/tclap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
