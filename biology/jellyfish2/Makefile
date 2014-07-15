# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	jellyfish
PORTVERSION=	2.1.3
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.genome.umd.edu/pub/jellyfish/

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
