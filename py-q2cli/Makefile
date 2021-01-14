# $FreeBSD$

PORTNAME=	q2cli
DISTVERSION=	2020.11.1
CATEGORIES=	wip biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line interface for QIIME 2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# Do these deps belong in other qiime ports?
RUN_DEPENDS=	${PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PKGNAMEPREFIX}bibtexparser>0:textproc/py-bibtexparser@${PY_FLAVOR} \
		${PKGNAMEPREFIX}biom-format>0:biology/py-biom-format@${PY_FLAVOR} \
		${PKGNAMEPREFIX}scikit-bio>0:wip/py-scikit-bio@${PY_FLAVOR} \
		${PKGNAMEPREFIX}CacheControl>0:www/py-cachecontrol@${PY_FLAVOR} \
		${PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PKGNAMEPREFIX}hdmedians>0:wip/py-hdmedians@${PY_FLAVOR} \
		${PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PKGNAMEPREFIX}q2-types>=2019.7.0:wip/py-q2-types@${PY_FLAVOR} \
		${PKGNAMEPREFIX}ijson>0:devel/py-ijson@${PY_FLAVOR} \
		${PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PKGNAMEPREFIX}q2templates>0:wip/py-q2templates@${PY_FLAVOR} \
		${PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOR} \
		${PKGNAMEPREFIX}jinja2-cli>0:textproc/py-jinja2-cli@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	qiime2

.include <bsd.port.mk>
