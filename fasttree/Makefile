# $FreeBSD: head/biology/fasttree/Makefile 449591 2017-09-10 20:55:38Z gerald $

PORTNAME=	FastTree
DISTVERSION=	2.1.10
CATEGORIES=	wip biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments

LICENSE=	GPLv2+

USES=		compiler:openmp

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/FastTree

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
