# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
#
# TODO
# Add core plugins

PORTNAME=	qiime2
PORTVERSION=	2017.2.0
CATEGORIES=	biology
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Quantitative Insights Into Microbial Ecology

LICENSE=	GPLv2

# QIIME 2 plugins
RUN_DEPENDS+=	${PKGNAMEPREFIX}q2-vsearch>=0:/usr/wip/biology/py-q2-vsearch \
		${PKGNAMEPREFIX}q2-deblur>=0:/usr/wip/biology/py-q2-deblur \
		${PKGNAMEPREFIX}q2-feature-classifier>=0:/usr/wip/biology/py-q2-feature-classifier

USES=		iconv python:2
USE_PYTHON=	distutils

USE_GITHUB=	yes

.include <bsd.port.mk>
