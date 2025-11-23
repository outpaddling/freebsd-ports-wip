PORTNAME=	wip-tools
DISTVERSION=	0.4.2-31
DISTVERSIONSUFFIX=	-gec4f04a
CATEGORIES=	wip ports-mgmt

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Update ports tree with work-in-progress ports
WWW=		https://github.com/outpaddling/freebsd-ports-wip

LICENSE=	BSD3CLAUSE

USES=		tar:xz
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_PROJECT=	freebsd-wip-tools

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/wip-poudriere-test \
		${STAGEDIR}${PREFIX}/sbin/wip-poudriere-pkg
	${INSTALL_MAN} ${WRKSRC}/Doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
