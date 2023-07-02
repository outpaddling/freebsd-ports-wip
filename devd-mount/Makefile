PORTNAME=	devd-mount
DISTVERSION=	0.0.0.2
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	devd-based automounter
WWW=		https://github.com/outpaddling/devd-mount

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	5d071e0fea757ca74a26200f6b3b0b0ac3fa25b4

NO_BUILD=	yes

PLIST_FILES=	sbin/devd-mount \
		etc/devd/devd-mount.conf \
		etc/devd-mount.conf.sample \
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
