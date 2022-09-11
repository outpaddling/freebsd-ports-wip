PORTNAME=	plasm
DISTVERSION=	0.0.0-40
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable Assembler
WWW=		https://github.com/outpaddling/plasm

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	papp:wip/papp

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	473fe9c6

pre-build:
	(cd ${WRKSRC} && ${MAKE} depend)

.include <bsd.port.mk>
