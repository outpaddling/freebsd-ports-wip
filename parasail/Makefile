PORTNAME=	parasail
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.3
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	SIMD C library for DNA alignments
WWW=		https://github.com/jeffdaily/parasail

LICENSE=	BSD2CLAUSE # Batelle BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		autoreconf libtool
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	jeffdaily

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
