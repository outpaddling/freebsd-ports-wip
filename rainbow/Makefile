# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	rainbow
PORTVERSION=	2.0.4
CATEGORIES=	wip biology
MASTER_SITES=	SF/bio-rainbow
DISTNAME=	rainbow_${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Short reads clustering and local assembly

# LICENSE=	unspecified

USES=		gmake

PLIST_FILES=	bin/rainbow bin/ezmsim bin/rbasm

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} \
		${WRKSRC}/rainbow \
		${WRKSRC}/ezmsim \
		${WRKSRC}/rbasm \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
