# Created by: Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
# $FreeBSD$

# http://tophat.cbcb.umd.edu/downloads/tophat-2.0.11.tar.gz
PORTNAME=	tophat
PORTVERSION=	2.0.11
CATEGORIES=	biology science
MASTER_SITES=	http://tophat.cbcb.umd.edu/downloads/

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=	A spliced read mapper for RNA-Seq

# Just for speed: Recent GCC has better optimizer
USE_GCC=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
# Hack to allow variable length arrays, which are not supported by ISO C++
USE_GCC=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libbam.a:../../biology/samtools
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	bowtie:../../biology/bowtie

CFLAGS+=	-Wno-unused

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
