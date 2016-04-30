# $FreeBSD$

PORTNAME=	wip-tools
PORTVERSION=	0.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Update ports tree with work-in-progress ports

NO_BUILD=	yes

USES=		tar:xz

RUN_DEPENDS=	svn:devel/subversion

PLIST_FILES=	sbin/wip-update \
		sbin/wip-reinstall-port \
		sbin/wip-poudriere-test \
		sbin/wip-copy-to-poudriere \
		man/man1/wip-update.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wip-update ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/wip-reinstall-port ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/wip-poudriere-test ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/wip-copy-to-poudriere \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/wip-update.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
