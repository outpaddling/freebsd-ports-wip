# $FreeBSD$

PORTNAME=	tensorflow
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.1
CATEGORIES=	wip science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Open source machine learning framework for everyone

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bazel>=0:devel/bazel

USES=		python
USE_GITHUB=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
