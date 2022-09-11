PORTNAME=	shrinkwrap
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-beta
CATEGORIES=	wip archivers

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	std::streambuf wrapper for compression formats.
WWW=		https://github.com/jonathonl/shrinkwrap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	jonathonl

CXXFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
