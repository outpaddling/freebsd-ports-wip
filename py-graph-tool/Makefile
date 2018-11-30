# $FreeBSD$

PORTNAME=	graph-tool
DISTVERSION=	2.27
CATEGORIES=	wip graphics python
MASTER_SITES=	https://downloads.skewed.de/graph-tool/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python module for manipulation and statistical analysis of graphs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	${PY_BOOST}

# Check python version requirement
USES=		python tar:bz2
USE_PYTHON=	autoplist distutils

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-boost-python=boost_python27

.include <bsd.port.mk>
