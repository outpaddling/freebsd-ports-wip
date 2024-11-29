PORTNAME=	peak-classifier
DISTVERSION=	0.1.4-20
DISTVERSIONSUFFIX=	-gacb3f2a
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Classify ChIP/ATAC-Seq peaks based on features provided in a GFF
WWW=		https://github.com/auerlab/peak-classifier

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend libbiolibc.so:wip/biolibc
RUN_DEPENDS=	bedtools:biology/bedtools \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		localbase python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

SHEBANG_FILES=	feature-view.py

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}

.include <bsd.port.mk>
