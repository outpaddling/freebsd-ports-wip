# $FreeBSD$
#
# Bugs: Conflicts with bgzip, tabix, epstopdf

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
		groff:textproc/groff
RUN_DEPENDS=	Rscript:math/R \
		gnuplot:math/gnuplot

USES=		cmake libtool shebangfix
SHEBANG_FILES=	scripts/epacts* scripts/*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	statgen
GH_PROJECT=	EPACTS

INSTALL_TARGET=	install-strip

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/mmSKAT/libs/mmSKAT.so \
		${STAGEDIR}${PREFIX}/lib/epactsR/libs/epactsR.so

.include <bsd.port.mk>
