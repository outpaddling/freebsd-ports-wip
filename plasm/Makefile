PORTNAME=	plasm
DISTVERSION=	0.0.0-32
CATEGORIES=	wip devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable Assembler

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	papp:wip/papp

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	3d41cf97

pre-build:
	(cd ${WRKSRC} && ${MAKE} depend)

.include <bsd.port.mk>
