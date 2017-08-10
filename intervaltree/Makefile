# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	intervaltree
PORTVERSION=	2015.12.13
CATEGORIES=	wip math

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Minimal C++ interval tree implementation

LICENSE=	MIT

PLIST_FILES=	bin/interval_tree_test include/${PORTNAME}/IntervalTree.h

# EKG Accepted pull request
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	c38e6838883ddf00d0d3b947c8274807b3869215

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# Needs <thread>, not available with clang port
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
