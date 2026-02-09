PORTNAME=       chip-pipeline1
# Update major version only if the metaport is overhauled
# Update minor version when adding or removing dependencies
# Update revision for all other changes
PORTVERSION=    0.1
CATEGORIES=     wip biology

MAINTAINER=     jwb@FreeBSD.org
COMMENT=        RNA sequencing pipeline metaport for
WWW=		https://NA

LICENSE=        BSD3CLAUSE

RUN_DEPENDS=    scythe>=0:wip/scythe \
		sickle>=0:wip/sickle \
		bwa>=0:biology/bwa \
		${PYTHON_PKGNAMEPREFIX}ceas>=0:wip/py-ceas \
		bowtie2>=0:biology/bowtie2 \
		tophat>=2.1.1:wip/tophat \
		cufflinks>=0:wip/cufflinks \
		${PYTHON_PKGNAMEPREFIX}MACS2>=2:biology/py-macs2 \
		meme>=0:wip/meme

# Unfinished
#               idr>=0:wip/idr

USES=           metaport python

.include <bsd.port.mk>
