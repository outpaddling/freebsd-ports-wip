# Created by: Jason Bacon <bacon@manatee.acadix.biz>
# $FreeBSD$

PORTNAME=	TransDecoder
PORTVERSION=	2.0.1
CATEGORIES=	biology
MASTER_SITES=	http://github.com/TransDecoder/TransDecoder/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	bacon@manatee.acadix.biz
COMMENT=

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Depends on bash

USES=		gmake
USE_GCC=	yes

#SHEBANG_FILES=	${WRKSRC}/transdecoder_plugins/Makefile

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/local/bin/bash|g' \
		${WRKSRC}/transdecoder_plugins/Makefile

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
