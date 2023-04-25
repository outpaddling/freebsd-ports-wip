PORTNAME=	bmv2
DISTVERSION=	1.15.0
CATEGORIES=	wip net

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Reference P4 software switch
WWW=		https://example.com/bmv2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libnanomsg.so:net/nanomsg \
		libthrift.so:devel/thrift-cpp

USES=		autoreconf libtool localbase:ldflags shebangfix
USE_GITHUB=	yes

SHEBANG_GLOB=	*.sh
GH_ACCOUNT=	p4lang
GH_PROJECT=	behavioral-model

GNU_CONFIGURE=	yes
# Temporary hack to make progress on build.  Should not be disabled.
CONFIGURE_ARGS=	--without-thrift
LDFLAGS+=	-L${LOCABBASE}/lib

.include <bsd.port.mk>
