PORTNAME=	freebsd-update-notify
DISTVERSION=	0.0.0.13
CATEGORIES=	wip deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Notify desktop user when FreeBSD updates are available
WWW=		https://github.com/outpaddling/freebsd-update-notify

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zenity:x11/zenity

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	9ae4662162e45f594cb2b8ac740f8b448af2fd2b

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	libexec/freebsd-update-notify \
		etc/cron.d/freebsd-update-notify \
		etc/cron.d/freebsd-update-cron

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update-notify \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/freebsd-update-notify.cron \
		${STAGEDIR}${PREFIX}/etc/cron.d/freebsd-update-notify
	${INSTALL_DATA} ${WRKSRC}/freebsd-update-cron.cron \
		${STAGEDIR}${PREFIX}/etc/cron.d/freebsd-update-cron

.include <bsd.port.mk>
