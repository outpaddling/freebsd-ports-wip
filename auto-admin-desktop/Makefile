PORTNAME=	auto-admin-desktop
DISTVERSION=	0.1.1
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable tools for automating systems management
WWW=		https://github.com/outpaddling/auto-admin

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	auto-admin>0:wip/auto-admin \
		rxvt-unicode>0:x11/rxvt-unicode

USES=		desktop-file-utils metaport

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	sbin/auto-admin-pause share/applications/auto-admin.desktop

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/sbin \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${FILESDIR}/auto-admin-pause ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/auto-admin.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
