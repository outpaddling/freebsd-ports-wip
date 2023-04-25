PORTNAME=	p4c
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3.8
CATEGORIES=	wip lang

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	P4 network language reference compiler
WWW=		https://example.com/p4c

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	flex:textproc/flex
LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libprotobuf.so:devel/protobuf

USES=		bison cmake
USE_GITHUB=	yes
GH_ACCOUNT=	p4lang
GH_TUPLE=	google:googletest:aa148eb:gtest/test/frameworks/gtest \
		p4lang:p4runtime:7a322f3:p4runtime/control-plane/p4runtime

WITH_DEBUG=	yes
# irgenerator seg faults during build with boehm_gc enabled
CMAKE_ARGS+=	-DENABLE_GC:BOOL=FALSE
LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
