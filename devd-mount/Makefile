PORTNAME=	devd-mount
DISTVERSION=	0.1.0-9
DISTVERSIONSUFFIX=	-g7da0b4c
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Automount tool utilizing devd notifications
WWW=		https://github.com/outpaddling/devd-mount

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

NO_BUILD=	yes
NO_ARCH=	yes

CONFLICTS_INSTALL=	automount

PLIST_FILES=	sbin/devd-mount \
		etc/devd/devd-mount.conf \
		"@sample etc/devd-mount.conf.sample" \
		man/man8/devd-mount.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/devd-mount ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/devd.conf \
		${STAGEDIR}${PREFIX}/etc/devd/devd-mount.conf
	${INSTALL_DATA} ${WRKSRC}/devd-mount.conf \
		${STAGEDIR}${PREFIX}/etc/devd-mount.conf.sample
	${INSTALL_MAN} ${WRKSRC}/Man/devd-mount.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
