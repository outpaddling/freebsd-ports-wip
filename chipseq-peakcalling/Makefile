# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	chip-pipeline1
PORTVERSION=	0.1
CATEGORIES=	wip biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA sequencing pipeline metaport for

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	scythe>=0:wip/scythe \
		sickle>=0:wip/sickle \
		bwa>=0:biology/bwa \
		${PYTHON_PKGNAMEPREFIX}ceas>=0:wip/py-ceas \
		bowtie2>=0:wip/bowtie2 \
		tophat>=2.1.1:wip/tophat \
		cufflinks>=0:wip/cufflinks \
		${PYTHON_PKGNAMEPREFIX}MACS2>=2:wip/py-macs2 \
		meme>=0:wip/meme

# Unfinished
#		idr>=0:wip/idr

USES=		metaport python

.include <bsd.port.mk>
