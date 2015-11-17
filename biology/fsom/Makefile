# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	fsom
PORTVERSION=	5105f1c93b738dcd6747ff03efb1092f6c3fddfb
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

CXXFLAGS+=	-fomit-frame-pointer -ffast-math

PLIST_FILES=	bin/fsom

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsom ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
