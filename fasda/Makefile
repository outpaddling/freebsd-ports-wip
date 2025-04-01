PORTNAME=	fasda
DISTVERSION=	0.1.5-50
DISTVERSIONSUFFIX=	-gc1bfc1d
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast and simple differential analysis
WWW=		https://github.com/auerlab/fasda

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend libbiolibc.so:wip/biolibc
RUN_DEPENDS=	stringtie>0:biology/stringtie \
		${PYTHON_PKGNAMEPREFIX}seaborn>=0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastcluster>=0:math/py-fastcluster@${PY_FLAVOR}

USES=		localbase python:run
USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
