# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	intervaltree
PORTVERSION=	2015.11.16
CATEGORIES=	math
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Minimal C++ interval tree implementation

# LICENSE=	BSDish

USES=		tar:xz

PLIST_FILES=	include/IntervalTree.h

ALL_TARGET=	interval_tree_test

post-patch:
	${REINPLACE_CMD} -e 's|g++|${CXX}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/IntervalTree.h \
		${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
