PORTNAME=	diskimage-tools
DISTVERSION=	0.3.1
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Convenience tools for manipulating disk images
WWW=		https://acadix.biz/diskimage-tools.php

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
