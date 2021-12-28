PORTNAME=	auto-admin-desktop
DISTVERSION=	0.1
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable tools for automating systems management

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	rxvt-unicode>0:x11/rxvt-unicode

USES=		metaport

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	share/applications/auto-admin.desktop

do-install:
	${MKDIR} -p ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/auto-admin.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
