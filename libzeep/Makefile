# $FreeBSD$

PORTNAME=		libzeep
DISTVERSIONPREFIX=	v
DISTVERSION=		3.0.3
CATEGORIES=		wip www

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Make it easy to create SOAP servers

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	mhekkel

MAKEFILE=	makefile
ALL_TARGET=	lib
MAKE_ENV=	BOOST=${PREFIX}

.include <bsd.port.mk>
