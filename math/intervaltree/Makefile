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

.include <bsd.port.mk>
