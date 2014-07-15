# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	jellyfish
PORTVERSION=	1.1.11
CATEGORIES=	biology
MASTER_SITES=	http://www.cbcb.umd.edu/software/jellyfish/

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

# Variable length arrays
USE_GCC=	yes

MAKE_JOBS_UNSAFE=yes

USE_LDCONFIG=	yes

LDFLAGS=	-lexecinfo
# GCC? -Wl,-rpath=${PREFIX}

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
