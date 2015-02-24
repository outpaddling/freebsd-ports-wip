# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	cdbfasta
PORTVERSION=	2010.07.22
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Fast indexing and retrieval of fasta records from flat file databases.

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdbfasta ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cdbyank ${STAGEDIR}${PREFIX}/bin
.include <bsd.port.mk>
