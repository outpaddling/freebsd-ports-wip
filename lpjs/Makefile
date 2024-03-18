PORTNAME=	lpjs
DISTVERSION=	0.0.0-371
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, Portable Job Scheduler
WWW=		https://github.com/outpaddling/LPJS/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxtend>=0.2.0.9:wip/libxtend
LIB_DEPENDS=	libxtend.so:wip/libxtend \
		libmunge.so:wip/munge
RUN_DEPENDS=	auto-admin>0:wip/auto-admin

USE_GITHUB=	yes
USE_RC_SUBR=	lpjs_dispatchd lpjs_compd

USERS=		lpjs
GROUPS=		${USERS}

GH_ACCOUNT=	outpaddling
GH_PROJECT=	LPJS
GH_TAGNAME=	80b6b61eb9f3bf299a416194cbbb0d8a384f5b6b

# Force debug symbols on until release
WITH_DEBUG=	yes

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
