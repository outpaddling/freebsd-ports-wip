PORTNAME=	freebsd-update-notify
DISTVERSION=	0.0.0.17
CATEGORIES=	wip deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Notify desktop user when FreeBSD updates are available
WWW=		https://github.com/outpaddling/freebsd-update-notify

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zenity:x11/zenity auto-admin:sysutils/auto-admin

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	ff7705bdc5fd6624d4ea850e50031676e9b65d53

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	libexec/freebsd-update-notify \
		libexec/freebsd-update-cron \
		"@sample etc/freebsd-update-notify.crontab.sample etc/cron.d/freebsd-update-notify" \
		"@dir etc/cron.d"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update-notify \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update-cron \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/freebsd-update-notify.crontab \
		${STAGEDIR}${PREFIX}/etc/freebsd-update-notify.crontab.sample

.include <bsd.port.mk>
