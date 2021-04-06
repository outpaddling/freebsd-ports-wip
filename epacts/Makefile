
PORTNAME=		epacts
DISTVERSIONPREFIX=	v
DISTVERSION=		3.4-rc-5
DISTVERSIONSUFFIX=	-g019bc8b
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Efficient and Parallelizable Association Container Toolbox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	Rscript:math/R \
		gnuplot:math/gnuplot \
		groff:textproc/groff \
		savvy>=0:wip/savvy
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhts.so:biology/htslib \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	Rscript:math/R \
		gnuplot:math/gnuplot \
		bash:shells/bash

USES=		cmake libtool shebangfix ssl
# USES=		cmake compiler:openmp libtool shebangfix

SHEBANG_FILES=	scripts/epacts* scripts/*.sh epactsR/configure

USE_GITHUB=	yes
GH_ACCOUNT=	statgen
GH_PROJECT=	EPACTS

CFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-fPIC -lbz2 -llzma -L${LOCALBASE}/lib -lcurl -lcrypto -lm

post-extract:
	${MV} ${WRKSRC}/scripts/epstopdf ${WRKSRC}/scripts/epacts-epstopdf

.include <bsd.port.mk>
