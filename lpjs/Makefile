PORTNAME=	lpjs
DISTVERSION=	0.0.0-386
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
GH_TAGNAME=	e70c97f01f5dfb3726b511695023097f1fc4aa85

# Force debug symbols on until release
WITH_DEBUG=	yes

pre-build:
	cd ${WRKSRC} && ${MAKE} depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
