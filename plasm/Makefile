PORTNAME=	plasm
DISTVERSION=	0.0.0-35
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable Assembler

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	papp:wip/papp

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	4765a01f

pre-build:
	(cd ${WRKSRC} && ${MAKE} depend)

.include <bsd.port.mk>
