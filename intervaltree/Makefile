# $FreeBSD$

PORTNAME=	intervaltree
PORTVERSION=	0.0.0.p2015.12.13
CATEGORIES=	wip math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Minimal C++ interval tree implementation

LICENSE=	MIT

PLIST_FILES=	bin/interval_tree_test include/${PORTNAME}/IntervalTree.h

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	8fc4be91866237995e1105689d84bece619f4663

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# FIXME: Blind hack.  Not sure why this is necessary.
.if ${ARCH} == i386
post-patch:
	${REINPLACE_CMD} -e 's|<bool, unsigned long>|<bool, unsigned int>|g' \
		${WRKSRC}/interval_tree_test.cpp
.endif

.include <bsd.port.post.mk>
