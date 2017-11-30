# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tophat
PORTVERSION=	2.1.1
CATEGORIES=	wip biology science
# Note: Distfiles on Github are not the same as those here
MASTER_SITES=	http://ccb.jhu.edu/software/tophat/downloads/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast splice junction mapper for RNA-Seq reads

LICENSE=	BSL

LIB_DEPENDS+=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	bowtie2:biology/bowtie2

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
