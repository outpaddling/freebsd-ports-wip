# Created by: Jason Bacon <jwb@FreeBSD.org>

PORTNAME=	wip-tools
DISTVERSION=	0.4.2-10
DISTVERSIONSUFFIX=	-gcf10831
CATEGORIES=	wip ports-mgmt

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Update ports tree with work-in-progress ports

LICENSE=	BSD3CLAUSE

USES=		tar:xz
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_PROJECT=	freebsd-wip-tools

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
