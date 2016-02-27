# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	chip-pipeline1
PORTVERSION=	0.1
CATEGORIES=	biology
MASTER_SITES=
DISTFILES=

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA sequencing pipeline metaport for

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	scythe>=0:/usr/wip/biology/scythe \
		sickle>=0:/usr/wip/biology/sickle \
		bwa>=0:${PORTSDIR}/biology/bwa \
		${PYTHON_PKGNAMEPREFIX}ceas>=0:/usr/wip/biology/py-ceas \
		bowtie2>=0:/usr/wip/biology/bowtie2 \
		tophat==2.0.12:/usr/wip/biology/tophat2012 \
		cufflinks>=0:/usr/wip/biology/cufflinks

# Unfinished
#		meme>=0:/usr/wip/biology/meme
#		idr>=0:/usr/wip/biology/idr
#		macs>=2:/usr/wip/biology/macs

USES=		python

NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.mk>
