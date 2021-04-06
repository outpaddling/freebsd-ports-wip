
PORTNAME=		cereal
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++11 library for serialization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	USCiLab

CFLAGS+=	-Wno-unused-private-field

.include <bsd.port.mk>
