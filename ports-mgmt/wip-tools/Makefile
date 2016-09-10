# $FreeBSD$

PORTNAME=	wip-tools
PORTVERSION=	0.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Update ports tree with work-in-progress ports

LICENSE=	BSD3CLAUSE

NO_BUILD=	yes

USES=		tar:xz

RUN_DEPENDS=	svn:devel/subversion

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
