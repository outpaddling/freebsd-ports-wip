PORTNAME=	lpjs
DISTVERSION=	0.0.0-74
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, Portable Job Scheduler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:wip/libxtend \
		libmunge.so:security/munge

USE_GITHUB=	yes
USE_RC_SUBR=	lpjs_dispatchd lpjs_compd

GH_ACCOUNT=	outpaddling
GH_PROJECT=	LPJS
GH_TAGNAME=	aa4bb8492bafd2b292733b039b84a751f007cc85

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
