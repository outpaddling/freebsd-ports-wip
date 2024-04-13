PORTNAME=	plasm
DISTVERSION=	0.0.0-68
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable Assembler
WWW=		https://github.com/outpaddling/plasm

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	papp:wip/papp

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	62bfb5a9a7843c843c9d2afb3c488d227e0a20c0

MAKE_ARGS+=	MANPREFIX=${PREFIX}/share

pre-build:
	(cd ${WRKSRC} && ${MAKE} depend)

.include <bsd.port.mk>
