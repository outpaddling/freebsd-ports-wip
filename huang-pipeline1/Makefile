PORTNAME=	huang-pipeline1
PORTVERSION=	0.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	RNA sequencing pipeline metaport for Spencer Huang
WWW=		https://NA

LICENSE=	BSD3CLAUSE

# Note: tophat depends on bowtie1.  Do we really want both bowties?
RUN_DEPENDS=	star>=0:wip/star \
		virusseq>=0:wip/virusseq \
		${PYTHON_PKGNAMEPREFIX}htseq>=0.6.1:wip/py-htseq

USES=		metaport python

.include <bsd.port.mk>
