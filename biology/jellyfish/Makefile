# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	jellyfish
PORTVERSION=	2.2.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.genome.umd.edu/pub/jellyfish/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

# Contains inline assembly code
ONLY_FOR_ARCHS=	amd64

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

USES=		compiler:c++11-lib compiler:openmp gmake libtool
USE_LDCONFIG=	yes

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
