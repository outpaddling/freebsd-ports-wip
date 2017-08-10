# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	smithwaterman
PORTVERSION=	2015.11.23
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Smith-waterman-gotoh alignment algorithm

LICENSE=	GPLv2

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	a64edb73e27e952f8bd5775d0d0354d0f82cdda6

INSTALL_TARGET=	install-strip

post-install:
	${CP} ${STAGEDIR}${PREFIX}/lib/libsw.so.1 \
		${STAGEDIR}${PREFIX}/lib/libsw.so

.include <bsd.port.mk>
