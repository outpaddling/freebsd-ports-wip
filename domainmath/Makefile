PORTNAME=	domainmath
PORTVERSION=	0.1.3
CATEGORIES=	wip math
MASTER_SITES=	SF/domainmath/DomainMathIDE_v0.1.x/
DISTNAME=	DomainMathIDE_v${PORTVERSION}
EXTRACT_SUFX=	.7z

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Java 1.7 GUI for Octave
WWW=		https://port.home.page/

EXTRACT_DEPENDS+=	p7zip:archivers/p7zip

FETCH_ARGS+=	-F

do-extract:
	(cd ${WRKDIR} && p7zip -d distfiles/${DISTNAME}${EXTRACT_SUFX})

.include <bsd.port.mk>
