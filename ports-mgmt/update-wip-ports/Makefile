# $FreeBSD$

PORTNAME=	update-wip-ports
PORTVERSION=	0.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Update ports tree with work-in-progress ports

NO_BUILD=	yes

USES=		tar:xz

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

PLIST_FILES=	bin/update-wip-ports bin/reinstall-wip-port man/man1/update-wip-ports.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/update-wip-ports ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/reinstall-wip-port ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/update-wip-ports.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
