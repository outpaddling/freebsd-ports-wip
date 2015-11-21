# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	fsom
PORTVERSION=	23c8bb0b0a1de866ef05ed2be283f67bca4d2f47
# FIXME: Is this the right category?
CATEGORIES=	biology

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tiny C library for managing SOM (Self-Organizing Maps) neural networks

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

CXXFLAGS+=	-fomit-frame-pointer -ffast-math

PLIST_FILES=	bin/fsom lib/libfsom.a

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
