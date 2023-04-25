PORTNAME=	bmv2
DISTVERSION=	1.15.0
CATEGORIES=	wip net

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Reference P4 software switch
WWW=		https://example.com/bmv2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		thrift-cpp>0:devel/thrift-cpp

USES=		autoreconf libtool localbase:ldflags shebangfix
USE_GITHUB=	yes

SHEBANG_GLOB=	*.sh
GH_ACCOUNT=	p4lang
GH_PROJECT=	behavioral-model

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
