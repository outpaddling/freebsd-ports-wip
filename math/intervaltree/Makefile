# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	intervaltree
PORTVERSION=	14e3ef9fb4f7987a797f2d07e36661b9764feef1
CATEGORIES=	math

MAINTAINER=	jwbacon@tds.net
COMMENT=	Minimal C++ interval tree implementation

# LICENSE=	BSDish

USES=		tar:xz

PLIST_FILES=	bin/interval_tree_test include/${PORTNAME}/IntervalTree.h

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
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
