# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/biology/fasttree/Makefile 449591 2017-09-10 20:55:38Z gerald $

PORTNAME=	FastTree
DISTVERSION=	2.1.10
CATEGORIES=	wip biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments

LICENSE=	GPLv2+

USES=		compiler:openmp

LDFLAGS+=	-lm

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/FastTree
MAKEFILE=	${FILESDIR}/Makefile

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include <bsd.port.mk>
