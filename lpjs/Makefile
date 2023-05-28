PORTNAME=	lpjs
DISTVERSION=	0.0.0-136
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
GH_TAGNAME=	53c8b8648a0f1a9731e3b96cc564830945c8a180

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
