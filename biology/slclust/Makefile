# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	slclust
PORTVERSION=	02022010
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	slclust/slclust
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jwbacon@tds.net>
COMMENT=	Single-linkage clustering with Jaccard similarity

WRKSRC=		${WRKDIR}/slclust

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slclust ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
