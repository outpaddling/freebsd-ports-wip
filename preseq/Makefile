PORTNAME=		preseq
DISTVERSION=		3.2.0
CATEGORIES=		wip biology
# Github-generated distfiles are incomplete
MASTER_SITES=		https://github.com/smithlabcode/preseq/releases/download/v${DISTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Predict yield of distinct reads from a genomic library
WWW=		https://github.com/smithlabcode/preseq

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhts.so:biology/htslib

USES=		gmake localbase

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-hts

.include <bsd.port.mk>
