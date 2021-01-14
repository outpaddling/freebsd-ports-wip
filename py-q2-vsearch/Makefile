# $FreeBSD$

PORTNAME=	q2-vsearch
PORTVERSION=	2020.11.1
CATEGORIES=	wip biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Vsearch plugin for QIIME 2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	vsearch>0:biology/vsearch

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	qiime2
# GH_TAGNAME=	0241adbb0ee5abf7317a22d37cccf35bf82973a6

.include <bsd.port.mk>
