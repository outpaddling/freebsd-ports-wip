PORTNAME=	jansson
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C library for encoding, decoding and manipulating JSON data
WWW=		https://example.com/jannson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool pathfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	akheron

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
