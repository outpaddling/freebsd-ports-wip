PORTNAME=	rna-pipeline1
PORTVERSION=	0.1
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	RNA sequencing pipeline metaport for
WWW=		https://NA

LICENSE=	BSD3CLAUSE

# Note: tophat depends on bowtie1.  Do we really want both bowties?
RUN_DEPENDS=	scythe>=0:wip/scythe \
		sickle>=0:wip/sickle \
		bowtie2>=0:wip/bowtie2 \
		tophat>=2.1.1:wip/tophat \
		cufflinks>=0:wip/cufflinks \
		${PYTHON_PKGNAMEPREFIX}htseq>=0.6.1:wip/py-htseq

USES=		metaport python

.include <bsd.port.mk>
