PORTNAME=	lpjs
DISTVERSION=	0.0.0-37
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, Portable Job Scheduler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_PROJECT=	LPJS
GH_TAGNAME=	6b574ea8e2d52cc12cfec2d30bb1b13f1a870364

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
