# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	tophat
PORTVERSION=	2.1.1
CATEGORIES=	biology science
MASTER_SITES=	http://ccb.jhu.edu/software/tophat/downloads/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast splice junction mapper for RNA-Seq reads

LICENSE=	ClArtistic

LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	bowtie2:/usr/wip/biology/bowtie2

GNU_CONFIGURE=	yes
USES=		gmake python

CFLAGS+=	-Wno-unused

MAKE_JOBS_UNSAFE=yes

# Debugging: builds on some machines and not others.  No differences in
# configure output.
pre-build:
	printenv > env
	alias >> env

.include <bsd.port.mk>
