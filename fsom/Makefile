# $FreeBSD$

PORTNAME=	fsom
PORTVERSION=	0.0.0p20151117
CATEGORIES=	wip science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tiny C library for managing SOM (Self-Organizing Maps) neural networks

LICENSE=	GPLv3

USES=		compiler:c++0x
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	56695e1611d824cda97f08e932d25d08419170cd

CXXFLAGS+=	-fomit-frame-pointer -ffast-math

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/fsom \
		include/fsom/convert.h \
		include/fsom/fsom.h \
		include/fsom/split.h \
		lib/libfsom.a

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
