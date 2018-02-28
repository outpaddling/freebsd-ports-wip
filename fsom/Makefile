# $FreeBSD$

PORTNAME=	fsom
PORTVERSION=	2015.11.21
CATEGORIES=	wip science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tiny C library for managing SOM (Self-Organizing Maps) neural networks

LICENSE=	GPLv3

USES=		compiler:c++0x
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	a83b4e82837a5fbe50788792e4f3bd1b69082417

CXXFLAGS+=	-fomit-frame-pointer -ffast-math

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

PLIST_FILES=	bin/fsom lib/libfsom.a \
		include/fsom/convert.h include/fsom/fsom.h include/fsom/split.h

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
