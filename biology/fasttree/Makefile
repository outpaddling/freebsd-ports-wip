# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

PORTNAME=	FastTree
PORTVERSION=	2.1.7
CATEGORIES=	biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.c

MAINTAINER=	jwbacon@tds.net
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments of nucleotide or protein sequences

USE_GCC=	any

CFLAGS+=	-DOPENMP -fopenmp -O3 -finline-functions -funroll-loops
LDFLAGS+=	-lm

PLIST_FILES=	bin/FastTree

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o FastTree ${DISTFILES} ${LDFLAGS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/FastTree ${STAGEDIR}${PREFIX}/bin
	
.include <bsd.port.mk>
