# $FreeBSD$

PORTNAME=	smithwaterman
PORTVERSION=	0.0.0.p2016.07.02
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Smith-waterman-gotoh alignment algorithm

LICENSE=	GPLv2

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	2610e259611ae4cde8f03c72499d28f03f6d38a7

INSTALL_TARGET=	install-strip

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${CP} ${STAGEDIR}${PREFIX}/lib/libsw.so.1 \
		${STAGEDIR}${PREFIX}/lib/libsw.so

.include <bsd.port.mk>
