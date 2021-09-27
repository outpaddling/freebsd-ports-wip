PORTNAME=	lpjs
DISTVERSION=	0.0.0-24
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, Portable Job Scheduler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_PROJECT=	LPJS
GH_TAGNAME=	32fb8bf8f55fed86eff9736f79ffd33a7db74eec

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
