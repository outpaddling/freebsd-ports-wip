PORTNAME=	freebsd-update-notify
DISTVERSION=	0.0.0.2
CATEGORIES=	wip deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Notify desktop user when FreeBSD updates are available
WWW=		https://github.com/outpaddling/freebsd-update-notify

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_TAGNAME=	c8670686a3b64c51fb7c49c7a792f9a6d0a50ad7

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	libexec/freebsd-update-notify \
		etc/cron.d/freebsd-update-notify

do-install:
	${MKDIR} -p ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update-notify \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/freebsd-update-notify.cron \
		${STAGEDIR}${PREFIX}/etc/cron.d/freebsd-update-notify

.include <bsd.port.mk>
