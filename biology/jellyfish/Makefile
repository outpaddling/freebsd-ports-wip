# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	jellyfish
PORTVERSION=	1.1.11
CATEGORIES=	biology
MASTER_SITES=	http://www.cbcb.umd.edu/software/jellyfish/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3

USES=		gmake libtool
GNU_CONFIGURE=	yes

# C++ variable length arrays
USES=		compiler:c++14-lang libtool

MAKE_JOBS_UNSAFE=yes

USE_LDCONFIG=	yes

LDFLAGS+=	-lexecinfo

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
