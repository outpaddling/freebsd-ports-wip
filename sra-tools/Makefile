# $FreeBSD$

PORTNAME=	sra-tools
PORTVERSION=	2.9.2
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI Sequence Read Archive toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libngs-sdk.so:biology/ngs-sdk

LIB_DEPENDS=	libngs-sdk.so:biology/ngs-sdk
USES=		gmake perl5
USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ngs-sdk-prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-ngs-sdk-prefix=${LOCALBASE}

.include <bsd.port.mk>
