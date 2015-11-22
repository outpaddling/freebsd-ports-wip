# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	fsom
PORTVERSION=	23c8bb0b0a1de866ef05ed2be283f67bca4d2f47
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tiny C library for managing SOM (Self-Organizing Maps) neural networks

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

USES=		compiler:c++0x

CXXFLAGS+=	-fomit-frame-pointer -ffast-math

PLIST_FILES=	bin/fsom lib/libfsom.a

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
