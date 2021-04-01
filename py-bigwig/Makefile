# $FreeBSD$

PORTNAME=	pyBigWig
DISTVERSION=	0.3.18
CATEGORIES=	wip python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon@orca.acadix.biz
COMMENT=	Python access to bigWig files using libBigWig

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		localbase python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
