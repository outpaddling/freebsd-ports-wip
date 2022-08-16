# Created by: Jason Bacon <jwb@FreeBSD.org>

PORTNAME=	EPC
DISTVERSION=	0.1.0-8
DISTVERSIONSUFFIX=	-g1417e76
CATEGORIES=	wip emulators

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Educational Perrsonal Computer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	twintk>0:wip/twintk \
		plasm>0:wip/plasm
LIB_DEPENDS=	libxtend.so:wip/libxtend
RUN_DEPENDS=	plasm:wip/plasm

#USES=		localbase
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

pre-build:
	${MAKE} depend

.include <bsd.port.mk>
