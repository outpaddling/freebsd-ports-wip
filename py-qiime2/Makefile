# $FreeBSD$

# TODO
# Add core plugins

PORTNAME=	qiime2
DISTVERSION=	2019.7.0
CATEGORIES=	wip biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	${PORTVERSION}
#DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quantitative Insights Into Microbial Ecology

LICENSE=	GPLv2

# QIIME 2 plugins
RUN_DEPENDS+=	${PKGNAMEPREFIX}q2-vsearch>=2019.7.0:wip/py-q2-vsearch@${PY_FLAVOR} \
		${PKGNAMEPREFIX}q2-deblur>=2019.7.0:wip/py-q2-deblur@${PY_FLAVOR} \
		${PKGNAMEPREFIX}q2-feature-classifier>=2019.7.0:wip/py-q2-feature-classifier@${PY_FLAVOR}

USES=		iconv python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes

.include <bsd.port.mk>
