PORTNAME=	htscodecs
DISTVERSION=	1.6.4
CATEGORIES=	wip biology
# Github generated distfiles are incomplete, so use custom tarball
MASTER_SITES=	https://github.com/samtools/htscodecs/releases/download/v1.6.4/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Custom CRAM codecs used for EXTERNAL block types
WWW=		https://github.com/samtools/htscodecs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		libtool

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
