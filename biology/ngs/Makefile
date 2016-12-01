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

ALL_TARGET=	subdirs

# Don't do this post-patch, since it modifies files with static patches.
pre-configure:
	${REINPLACE_CMD} -e 's|x86_64|amd64|g' ${WRKSRC}/*/setup/konfigure.perl

.include <bsd.port.mk>
