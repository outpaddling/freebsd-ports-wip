# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/biology/fasttree/Makefile 449591 2017-09-10 20:55:38Z gerald $

PORTNAME=	FastTree
PORTVERSION=	2.1.10
CATEGORIES=	wip biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments

LICENSE=	GPLv2+

USES=		compiler:openmp

CFLAGS+=	-DOPENMP -fopenmp -O3 -finline-functions -funroll-loops
LDFLAGS+=	-lm

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/FastTree

do-extract:
	#${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o FastTree ${DISTFILES} ${LDFLAGS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/FastTree ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
