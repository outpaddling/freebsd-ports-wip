PORTNAME=	lpjs
DISTVERSION=	0.0.0-193
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, Portable Job Scheduler
WWW=		https://github.com/outpaddling/LPJS/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend \
		libmunge.so:security/munge

USE_GITHUB=	yes
USE_RC_SUBR=	lpjs_dispatchd lpjs_compd

GH_ACCOUNT=	outpaddling
GH_PROJECT=	LPJS
GH_TAGNAME=	6e07ef63048a6dc3c5c5f6ad898e642c872aee0b

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
