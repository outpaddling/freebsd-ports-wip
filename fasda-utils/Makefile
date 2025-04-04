PORTNAME=	fasda-utils
DISTVERSION=	0.0.0-3
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast and simple differential analysis extras
WWW=		https://github.com/auerlab/fasda-utils

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seaborn>=0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastcluster>=0:math/py-fastcluster@${PY_FLAVOR}

USES=		python:run shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	Scripts/heatmap.py

GH_ACCOUNT=	auerlab
GH_TAGNAME=	eb807e741241e15db049409e5d401d21d91eb8f2

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}

.include <bsd.port.mk>
