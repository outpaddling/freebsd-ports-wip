PORTNAME=	FastTree
DISTVERSION=	2.1.10
PORTREVISION=	5
CATEGORIES=	wip biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments
WWW=		https://www.microbesonline.org/fasttree/

LICENSE=	GPLv2+

BROKEN_armv6=		fails to compile: FastTree-2.1.10.c:305:10: 'omp.h' file not found
BROKEN_armv7=		fails to compile: FastTree-2.1.10.c:305:10: 'omp.h' file not found

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/FastTree

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
