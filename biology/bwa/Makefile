# Created by: Jason Bacon <bacon@freebie.acadix.biz>
# $FreeBSD$

PORTNAME=	bwa
PORTVERSION=	0.7.9a
CATEGORIES=	biology science
MASTER_SITES=	SF/bio-bwa/

USE_BZIP2=	yes

MAINTAINER=	bacon@freebie.acadix.biz
COMMENT=	Burrows-Wheeler sequence aligner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bwa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
