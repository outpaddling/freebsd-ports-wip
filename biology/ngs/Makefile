# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	ngs
PORTVERSION=	1.3.0
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	NCBI NGS language bindings

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${STAGEDIR}${PREFIX}

ALL_TARGET=	subdirs

# Don't do this post-patch, since it modifies files with static patches.
# Be sure to update static patches only after patch, not any later stages.
pre-configure:
	${REINPLACE_CMD} -e 's|x86_64|amd64|g' ${WRKSRC}/*/setup/konfigure.perl
	${REINPLACE_CMD} -e 's|lib64|lib|g' ${WRKSRC}/*/setup/install.perl
	${LN} -s ${WRKSRC}/ngs-sdk/ngs/unix/x86_64 ${WRKSRC}/ngs-sdk/ngs/unix/amd64

.include <bsd.port.mk>
