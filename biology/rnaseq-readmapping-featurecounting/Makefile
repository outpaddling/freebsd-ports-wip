# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	rna-pipeline1
PORTVERSION=	0.1
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA sequencing pipeline metaport for

LICENSE=	BSD3CLAUSE

# Note: tophat depends on bowtie1.  Do we really want both bowties?
RUN_DEPENDS=	scythe>=0:/usr/wip/biology/scythe \
		sickle>=0:/usr/wip/biology/sickle \
		bowtie2>=0:/usr/wip/biology/bowtie2 \
		tophat>=2.1.1:/usr/wip/biology/tophat \
		cufflinks>=0:/usr/wip/biology/cufflinks \
		${PYTHON_PKGNAMEPREFIX}htseq>=0.6.1:/usr/wip/biology/py-htseq

USES=		metaport python

.include <bsd.port.mk>
