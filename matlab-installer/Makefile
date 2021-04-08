PORTNAME=	matlab-installer
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	wip math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Easy installation of Linux Matlab(r) on FreeBSD

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	auto-ask:sysutils/auto-admin \
		linux-c7-java-1.8.0-openjdk>0:wip/linux-c7-java-1.8.0-openjdk \
		linux-c7-pam>0:wip/linux-c7-pam \
		linux-c7-pam>0:wip/linux-c7-audit-libs \
		linux-c7-pam>0:wip/linux-c7-libcap-ng

USES=		linux tar:xz
USE_LINUX=	dri devtools

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/matlab-installer.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
