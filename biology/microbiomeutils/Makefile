# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	microbiomeutil
PORTVERSION=	r20110519
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	microbiomeutil

MAINTAINER=	jwbacon@tds.net
COMMENT=	Utilities for processing and analyzing 16S rRNA genes

LICENSE=	BSD4CLAUSE

USES=		tar:tgz
BUILD_DEPENDS=	cdbfasta>=2010.07.22:/usr/wip/biology/cdbfasta
WORKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} \
		-e 's|gcc|$${CC}|g' \
		${WRKSRC}/NAST-iEr/Makefile
do-install:
	${MV} ${WRKSRC}/AmosCmp16Spipeline ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MV} ${WRKSRC}/ChimeraSlayer ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MV} ${WRKSRC}/NAST-iEr ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MV} ${WRKSRC}/TreeChopper ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MV} ${WRKSRC}/WigeoN ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MV} ${WRKSRC}/RESOURCES ${STAGEDIR}${PREFIX}/${PORTNAME}
.include <bsd.port.mk>
