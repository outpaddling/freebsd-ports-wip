# $FreeBSD$

PORTNAME=	ParaFly
# Test new versions with Trinity before upgrading
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Process multiple commands in parallel on a single server

LICENSE=	BSD3CLAUSE

USES=		tar:tgz
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

CXXFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp

PLIST_FILES=	bin/ParaFly

.include <bsd.port.mk>
