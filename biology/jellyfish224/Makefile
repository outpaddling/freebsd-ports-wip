# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	jellyfish
PORTVERSION=	2.2.4
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

USES=		autoreconf compiler:openmp libtool

USE_GITHUB=	yes
GH_ACCOUNT=	gmarcais
GH_PROJECT=	Jellyfish
GH_TAGNAME=	v${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

CXXFLAGS+=	-std=c++0x

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
