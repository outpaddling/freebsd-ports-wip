PORTNAME=	lpjs
DISTVERSION=	0.0.0-23
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, Portable Job Scheduler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_PROJECT=	LPJS
GH_TAGNAME=	0ecad808be0dfc80e48bcb9b6b7baa1de76b92c6

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
