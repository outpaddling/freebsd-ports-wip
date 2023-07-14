PORTNAME=	freebsd-update-notify
DISTVERSION=	0.0.0.8
CATEGORIES=	wip deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Notify desktop user when FreeBSD updates are available
WWW=		https://github.com/outpaddling/freebsd-update-notify

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zenity:x11/zenity

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	77fa357e9ff40201e9f6089d67dc4157c2d4d50c

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	libexec/freebsd-update-notify \
		etc/cron.d/freebsd-update-notify

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update-notify \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/freebsd-update-notify.cron \
		${STAGEDIR}${PREFIX}/etc/cron.d/freebsd-update-notify

.include <bsd.port.mk>
