# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	tophat
PORTVERSION=	2.1.1
CATEGORIES=	biology science
MASTER_SITES=	http://ccb.jhu.edu/software/tophat/downloads/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Spliced read mapper for RNA-Seq

LICENSE=	ClArtistic

BUILD_DEPENDS=	samtools01==0.1.19:/usr/wip/biology/samtools0119
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	bowtie:/usr/wip/biology/bowtie \
		samtools01==0.1.19:/usr/wip/biology/samtools0119

GNU_CONFIGURE=	yes
USES=		gmake python

CFLAGS+=	-Wno-unused

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
