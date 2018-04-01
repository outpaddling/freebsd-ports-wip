# $FreeBSD$
#
# Bugs: Conflicts with bgzip, tabix, epstopdf

PORTNAME=	epacts
PORTVERSION=	0.0.0p20170222
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Efficient and Parallelizable Association Container Toolbox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	Rscript:math/R \
		gnuplot:math/gnuplot
RUN_DEPENDS=	Rscript:math/R \
		gnuplot:math/gnuplot

GNU_CONFIGURE=	yes

USES=		autoreconf libtool shebangfix
SHEBANG_FILES=	scripts/epacts* scripts/*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	statgen
GH_PROJECT=	EPACTS
GH_TAGNAME=	a5209db1b3929c4dd2f15f27ea085edf3a634ee7

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}

INSTALL_TARGET=	install-strip

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/mmSKAT/libs/mmSKAT.so \
		${STAGEDIR}${PREFIX}/lib/epactsR/libs/epactsR.so

.include <bsd.port.mk>
