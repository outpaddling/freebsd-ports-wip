# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	intervaltree
PORTVERSION=	f21e1e973175c6f4f2e7b153ba312177309bdbae
CATEGORIES=	math

MAINTAINER=	jwbacon@tds.net
COMMENT=	Minimal C++ interval tree implementation

# LICENSE=	BSDish

USES=		tar:xz

PLIST_FILES=	include/${PORTNAME}/IntervalTree.h

ALL_TARGET=	interval_tree_test

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's|g++|${CXX}|g' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/IntervalTree.h \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
