# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	slclust
PORTVERSION=	02022010
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	slclust/slclust
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com>
COMMENT=	Single-linkage clustering with Jaccard similarity

WRKSRC=		${WRKDIR}/slclust

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slclust ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
