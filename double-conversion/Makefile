# Created by: Waitman Gobble <waitman@waitman.net>
# $FreeBSD: head/devel/double-conversion/Makefile 493133 2019-02-16 23:30:01Z yuri $

PORTNAME=	double-conversion
PORTVERSION=	3.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	waitman@waitman.net
COMMENT=	Binary-decimal and decimal-binary routines for IEEE doubles

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_aarch64=	Fails to build: Target architecture was not detected as supported by Double-Conversion

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
