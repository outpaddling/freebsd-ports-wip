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

RUN_DEPENDS=	cdbfasta>=2010.07.22:/usr/wip/biology/cdbfasta \
		ncbi-toolkit>=2012.06.20:${PORTSDIR}/biology/ncbi-toolkit

USES=		tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} \
		-e 's|gcc|$${CC}|g' \
		${WRKSRC}/NAST-iEr/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NAST-iEr/NAST-iEr ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
