# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	intervaltree
PORTVERSION=	49a0e290efaaa760e0b03e52ca18ac03e7582f23
CATEGORIES=	math

MAINTAINER=	jwbacon@tds.net
COMMENT=	Minimal C++ interval tree implementation

# LICENSE=	BSDish

USES=		tar:xz

PLIST_FILES=	bin/interval_tree_test include/${PORTNAME}/IntervalTree.h

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	${PORTVERSION}

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# Needs c++0x
.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

# FIXME: Blind hack.  Not sure why this is necessary.
.if ${ARCH} == i386
post-patch:
	${REINPLACE_CMD} -e 's|<bool, unsigned long>|<bool, unsigned int>|g' \
		${WRKSRC}/interval_tree_test.cpp
.endif

.include <bsd.port.post.mk>
