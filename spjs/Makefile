PORTNAME=	spjs
DISTVERSION=	0.0.0-11
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simple, Portable Job Scheduler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_PROJECT=	SPJS
GH_TAGNAME=	3d83fe825dc6144c63b06efe1fe1d49aad20cd81

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
