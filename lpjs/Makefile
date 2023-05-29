PORTNAME=	lpjs
DISTVERSION=	0.0.0-139
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
GH_TAGNAME=	953af26cbcba1a749acded90e7a6c86d8af5b3eb

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
