# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=		jellyfish
PORTVERSION=		2.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=		biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3

# Contains inline assembly code
ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS+=	yaggo:/usr/wip/devel/yaggo

GNU_CONFIGURE=	yes

USES=		autoreconf compiler:c++11-lib compiler:openmp libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gmarcais
GH_PROJECT=	Jellyfish

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
