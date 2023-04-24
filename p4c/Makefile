PORTNAME=	p4c
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3.8
CATEGORIES=	wip lang

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	P4 network language reference compiler
WWW=		https://example.com/p4c

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bison>0:devel/bison

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	p4lang
GH_TUPLE=       google:googletest:aa148eb:gtest/test/frameworks/gtest \
		p4lang:p4runtime:7a322f3:p4runtime/control-plane/p4runtime

LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
